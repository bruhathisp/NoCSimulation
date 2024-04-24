//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 



import messages.NoCMessages;
import network.CPU;
import network.IO;
import network.Router;

network NoCSimulation
{
    submodules:
        cpu: CPU {
            @display("p=100,150");
        }
        io: IO {
            @display("p=300,150");
        }
        router: Router {
            @display("p=200,100");
        }
        trafficAnalyzer: TrafficAnalyzer {
            @display("p=200,200");
        }
    connections:
        cpu.out --> router.in;
        router.out --> cpu.in;
        io.out --> router.in;
        router.out --> io.in;
        
        // Connect the Router and IO outputs to the TrafficAnalyzer for monitoring
        router.out --> trafficAnalyzer.in;
        io.out --> trafficAnalyzer.in;
}
