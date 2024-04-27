# NoCSimulation
Dynamic Optimization of Network-on-Chip

# NoCTune Project README

## Overview

NoCTune is an advanced simulation framework developed to optimize Network-on-Chip (NoC) systems using Reinforcement Learning (RL). This project integrates an OMNeT++ simulation environment with a custom-developed Actor-Critic model in PyTorch to dynamically adjust NoC configurations based on real-time performance metrics.

## Goals

The primary goal of NoCTune is to design a NoC that is area and power efficient while achieving optimal performance in terms of latency and bandwidth. The simulation considers various traffic patterns and workload scenarios on a SoC that includes CPU and IO peripherals accessing system memory through a weighted arbiter.

1. (Write pseudocode to measure average latency and bandwidth using the simulator provided monitor output (as shown in Table 1.0). The pseudocode needs to be efficient and robust.)[https://github.com/bruhathisp/NoCSimulation/goals/Goal1/README.md]
2. (Using Reinforced Learning to arrive at the optimal parameters listed above. Put together a design document. Describe the RL framework consisting of states/behaviors, actions and rewards. You need to also advise which RL algorithm (ex: DQN, SARSA, Actor-Critic, etc.) is best suited for this problem statement. You need not develop or write the  RL algorithm. ) [https://github.com/bruhathisp/NoCSimulation/goals/Goal2/README.md]

## [Demo Video](https://www.youtube.com/watch?v=8IhDGbxIHnk)

## Features

- **Custom NoC Simulation Environment**: Simulates complex interactions within a SoC, including data flows between CPU, IO peripherals, and system memory.
- **Dynamic Routing and Buffer Management**: Uses real-time performance data to adjust routing paths and buffer sizes.
- **Actor-Critic Reinforcement Learning Model**: Optimizes system configurations for latency, bandwidth, and power consumption.
- **Performance Monitoring**: Tracks and adjusts system performance based on predefined thresholds for latency, bandwidth, buffer occupancy, and power consumption.

## Installation

### Prerequisites

- Python 3.6+
- PyTorch 1.7+
- Gym 0.17+
- OMNeT++ 6.0.3

### Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-repository/NoCTune.git
   cd NoCTune
   ```

2. **Install Python dependencies**:
   ```bash
   pip install torch gym numpy
   ```

3. **Set up OMNeT++** (Assuming OMNeT++ is already installed and configured):
   - Configure the OMNeT++ environment to integrate with the Python scripts.

4. **Build the simulation**:
   ```bash
   cd src
   make makefiles
   make
   ```

## Usage

### Running the Simulation

1. Installation Guide of Omnetpp - https://doc.omnetpp.org/omnetpp/InstallGuide.pdf 

2. **Run the reinforcement learning model** 

### Configuration

Adjust the `omnetpp.ini` file to set different simulation parameters like traffic patterns, buffer sizes, and arbitration weights.

## Custom Environment Setup

The `NoCEnv` class in `model.py` interfaces with the NoC simulator. It manages the complexities of system states, actions, and reward calculations.

## Architecture

### Modules

- **network/**: Contains OMNeT++ modules like CPU, IO, Router, and Arbitrator.
- **util/**: Includes utilities like the TestBench module for testing.
- **model/**: Contains the Actor-Critic model implemented in PyTorch.
- **messages/**: Definitions for custom message types used in the simulation.

### Reinforcement Learning Model

The Actor-Critic model uses the following key components:
- **Actor Loss**: Encourages the policy to take actions that lead to higher returns.
- **Critic Loss**: Penalizes inaccurate predictions of future returns.
- **Entropy Bonus**: Encourages exploration by preventing premature convergence.

## Contributing

Contributions are welcome. Please fork the repository and submit pull requests with your enhancements.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contact

Your Name - bruhathisathya@gmail.com

Project Link: https://github.com/bruhathisp/NoCSimulation/

