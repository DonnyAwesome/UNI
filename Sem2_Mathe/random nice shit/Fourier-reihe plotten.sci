//bin aufgabe 3

T = 2;
t = linspace(0,2*T);
a0 = 1;
w = 2*%pi/T;
p = a0/2;

for k = 1:10 
    
    p = p + ((1-(-1)^k)/k)*cos(k*w*t)
    
end

figure(1);
clf();
subplot(2,2,1);
plot(t, p, 'black')

for k= 1:10
    a(k) = sum((1-(-1)^k)/k);
    b(k) = sum(1/k^2);
end

c = [a0/2;(a - %i*b)/2];
subplot(2,2,3);
bar(0:10, abs(c), 'red');
title('Betragsspektrum');
subplot(2,2,4);
bar(0:10, atan(imag(c), real(c)), 'blue');
title('Phasensprektum');
