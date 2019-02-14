exec dgl.sci

figure(1);
clf;
mtlb_axis([0 5 -60 10])

x = 0;      //initalisierung
y = 3;      //initialsierung
h = 0.1;    //step size

while (x<=5)
    plot(x, y, 'o');
    y = y + h*dgl(x, y);
    x = x + h
    sleep(100)
end
