//Polarkoodinatensystem

z = [1+%i -1+%i -%i];
re = real(z);
im = imag(z);
plot(re, im, '*r') //quadratisches Koordinatenssystem
xgrid;
mtlb_axis([-2 2 -2 2]);


r = abs(z);
phi = atan(im, re);
polarplot(phi, r, -1); //komplexes Koordinatenssystem
