import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.distributions import Categorical

class ActorCritic(nn.Module):
    def __init__(self, num_inputs, num_actions):
        super(ActorCritic, self).__init__()
        self.common = nn.Sequential(
            nn.Linear(num_inputs, 128),
            nn.ReLU(),
            nn.Linear(128, 128),
            nn.ReLU()
        )
        self.actor = nn.Linear(128, num_actions)
        self.critic = nn.Linear(128, 1)

    def forward(self, x):
        x = self.common(x)
        action_probs = torch.softmax(self.actor(x), dim=-1)  # Softmax for a categorical action space
        state_values = self.critic(x)
        return action_probs, state_values

def train(env, model, num_episodes):
    optimizer = optim.Adam(model.parameters())
    for episode in range(num_episodes):
        state = env.reset()
        log_probs = []
        values = []
        rewards = []
        masks = []
        entropy = 0

        while True:
            state = torch.FloatTensor(state).unsqueeze(0)
            action_probs, state_value = model(state)

            dist = Categorical(action_probs)
            action = dist.sample()
            next_state, reward, done, _ = env.step(action.item())

            log_prob = dist.log_prob(action)
            entropy += dist.entropy().mean()

            log_probs.append(log_prob)
            values.append(state_value)
            rewards.append(torch.tensor([reward], dtype=torch.float32))
            masks.append(torch.tensor([1-done], dtype=torch.float32))

            state = next_state

            if done:
                break

        next_state = torch.FloatTensor(next_state).unsqueeze(0)
        _, next_value = model(next_state)
        returns = compute_returns(next_value, rewards, masks)

        log_probs = torch.cat(log_probs)
        returns = torch.cat(returns).detach()
        values = torch.cat(values)

        advantage = returns - values
        actor_loss = -(log_probs * advantage.detach()).mean()
        critic_loss = 0.5 * advantage.pow(2).mean()

        loss = actor_loss + critic_loss - 0.001 * entropy

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        if episode % 100 == 0:
            print(f'Episode {episode}: Loss {loss.item()}')

def compute_returns(next_value, rewards, masks, gamma=0.99):
    R = next_value
    returns = []
    for step in reversed(range(len(rewards))):
        R = rewards[step] + gamma * R * masks[step]
        returns.insert(0, R)
    return returns

# Example usage
env = NoCEnv()  # Ensure you have this environment set up as per previous descriptions
model = ActorCritic(env.observation_space.shape[0], env.action_space.n)
train(env, model, num_episodes=1000)
