# Josh Cupp - Pandemic Simulation
Uses the SIR model (susceptible, infected, recovered) to simulate what a pandemic might look like in a community, and is  
based on the variables that are used in the config.json file

## json variables

### game{} is used to change the heigth and width of the games window size.
It also has a variable for fps which stands for frames per second and was made to make he game run smoother

### Sim variables

Social Distancing - A bool that you could toggle on/off based on whether they practice social distancing

Social Distance - The distance that they will attempt to stay at 

Infection Radius - An integer that determines how close a disease is able to spread.

Infection rate - The rate at which the virus will spread to people. This rate can be reduced through social distancing  
and wearing maskes. The infection rate goes up the more that people are in the vicinity of the infection radius.

Population_count - The total amount of people in the simulaition

initial_infection = People who are initially infected.

initial_susceptible - People who are susceptible start out with a greater chance to contract an illness. This 
can be due to a variety of things from age to where you live geographically.

infection_duration -amount of time is takes for someone to recover from the illness and not be at risk of spreading 
it too other people as well as having basic immunity 

num_infected - An integer that kept track of how many people became infected.
