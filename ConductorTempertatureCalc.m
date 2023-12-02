prompt = "What is the cross sectional area of the material";
A = input(prompt);
prompt = "what current is running through the material?";
I = input(prompt);
prompt = "what is the resistivity of your material?";
r0 = input(prompt);
prompt = "How long is the event?";
dt = input(prompt);
prompt = "What is the density of the material?";
p = input(prompt);
prompt = "What is the specific heat capacity of your material?";
C = input(prompt);

dT = ((I^2)*r0*dt)/(A*p*C);

fprintf("Change in temperature is %s degrees celsius", num2str(dT))

