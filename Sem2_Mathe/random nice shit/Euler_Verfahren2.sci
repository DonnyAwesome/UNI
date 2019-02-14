exec dgl2.sci

figure(1);
clf;
mtlb_axis([0 20 -1.5 3])

t = 0;
z = [3;0]
h = 0.1;

while(t < 6 * %pi)
    plot(t, z(1), 'ob');
    plot(t, z(2), '*r');
    z = z + h*dgl2(t, z)
    t = t + h
    sleep(100)
end
