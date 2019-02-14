//2. Schubild von f(x,y)
clf()

x = -2:0.05:2;
y = 0:.05:4;

//x = linspace(-2, 2);
//y = linspace(0, 4);

[X, Y] = meshgrid(x, y)

F = X.^2 + Y.^2;
surf(X, Y, F);


//Achsenbeschriftung
a = gca();          //
a.font_size = 2;    //Schriftgröße für x,y,z scala

xlabel('x-Achse', 'fontsize', 5)
ylabel('y-Achse', 'fontsize', 5)
zlabel('z-Achse', 'fontsize', 5)
