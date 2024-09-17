D = 0.75;
a0 = 100*D;
a1 = a(1);
a2 = a(2);
a3 = a(3);
f0 = 0;
f1 = 10000;
f2 = 20000;
f3 = 30000;

%scatter(log(f0),a0,log(f1),a1,log(f2),a2,log(f3),a3);
x = [f0 f1 f2 f3];
y = [a0 a1 a2 a3];
scatter(x,y);

%a1n = ((2*Vg)/(1*pi))*sin(1*pi*D);
%a2n = ((2*Vg)/(2*pi))*sin(2*pi*D);
%a3n = ((2*Vg)/(3*pi))*sin(3*pi*D);

%x1 = [f0 f1 f2 f3];
%y1 = [a0 a1n a2n a3n];
%scatter(x1,y1);

function an = a(n)
    R = 5;          % Rload
    L = 1.3e-3;     % Inductance
    C = 16.7e-6;    % Capacitance
    Vg = 100;       % Input Voltage

    f = 20000;       % Switching Frequency
    D = .75;        % Duty Cycle
    fnew = f*n;
    ZR = R;
    ZL = 1i*2*pi*fnew*L;
    ZC = 1/(1i*2*pi*fnew*C);
    Z1 = ZL;
    Z2 = ((ZR*ZC)/(ZR+ZC));
    Zdiv = (Z2/(Z1+Z2));

    a = ((2*Vg)/(n*pi))*sin(n*pi*D);
    
    an = abs(a*abs(Zdiv));
end

