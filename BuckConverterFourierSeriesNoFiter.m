R = 5;          % Rload
L = 1.3e-3;     % Inductance
C = 16.7e-6;    % Capacitance
Vg = 100;       % Input Voltage

f = 10e3;       % Switching Frequency
f0 = 0;
f1 = f;
f2 = f*2;
f3 = f*3;


D = .75;        % Duty Cycle

a0 = 100*D;
a1 = ((2*Vg)/(1*pi))*sin(1*pi*D);
a2 = ((2*Vg)/(2*pi))*sin(2*pi*D);
a3 = ((2*Vg)/(3*pi))*sin(3*pi*D);

x = [f0 f1 f2 f3];
y = [a0 a1 a2 a3];
scatter(x,y);