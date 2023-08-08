# viscosity-nanofluid-Ansys-Fluent-UDF
This UDF defines a function that computes the viscosity of a nanofluid at a given cell and thread in Fluent. A nanofluid is a fluid that contains suspended nanoparticles that can enhance its thermal and electrical properties. The UDF uses the following parameters and variables:

•  cell_viscosity: the name of the user-defined function that takes two arguments: c and t.

•  c: a variable that represents a cell in the cell loop.

•  t: a pointer to the thread structure of the cell zone where the viscosity is calculated.

•  mu_base: a scalar that represents the viscosity of the base fluid. It has units of kg/m.s.

•  mu_nanofluid: a scalar that represents the viscosity of the nanofluid. It has units of kg/m.s.

•  phi: a scalar that represents the volume fraction of the nanoparticle in the nanofluid. It is a dimensionless parameter that represents

the ratio of
the nanoparticle volume to
the fluid volume in a given region. It is given by $$\phi = \frac{V_p}{V_f}$$ where $V_p$ is
the total volume
of
the nanoparticles and $V_f$ is
the total volume
of
the fluid. It has a constant value of 0.01.
•  temp: a scalar that represents the temperature of the fluid zone. It has units of K.

•  C_T: a macro that returns the temperature of the cell c and thread t.

The UDF performs the following steps:


It defines some constants and variables for the simulation.
It calculates the temperature of the fluid zone using C_T and stores it in temp.
It calculates the viscosity of the base fluid using a piecewise polynomial expression based on temp and stores it in mu_base. The expression is given by $$\mu_{base} = \begin{cases} 5.398500844 & \text{if } T < 285.15 \ 3.661e2 - 3.0154 T + 8.3409e-3 T^2 - 7.723e-6 T^3 & \text{if } 285.15 \leq T \leq 373.15 \ 23.165 - 0.1476 T + 3.617e-4 T^2 - 3.9844e-7 T^3 + 1.6543e-10 T^4 & \text{if } 317.15 \leq T \leq 698.15 \ 0.132781558 & \text{if } T > 698.15 \end{cases}$$ where $T$ is
the temperature
of
the base fluid.
It converts the viscosity from mPa s to kg m^-1 s^-1 by multiplying mu_base by 1e-3.
It calculates the viscosity of the nanofluid using an empirical formula based on phi and mu_base and stores it in mu_nanofluid. The formula is given by $$\mu_{nanofluid} = \mu_{base} (123 \phi^2 + 7.3 \phi + 1)$$ where $\phi$ is
the volume fraction
of
the nanoparticle and $\mu_{base}$ is
the viscosity
of
the base fluid.
It returns mu_nanofluid as
the output
of
the function.

The UDF can be used to model fluid flow problems with nanofluids, such as lubrication, drag reduction, or mixing enhancement. 
