//bin Fallschirmspringer
exec FallschirmspringerDGL.sci

figure(1);
clf;
mtlb_axis([0 30 0 100])

t = 0;
z = [100;-50]
h = 0.01;

while(z(1) >= 0)
    plot(t, z(1), '+r');
    z = z + h*FallschirmspringerDGL(t, z)
    t = t + h
    //sleep(100)
end
