function zp = FallschirmspringerDGL(t, z)
    
    g = 9,81;
    m = 100;
    cw = 1,4;
    p = 1,2;
    r = 5;
    
    zp = [z(2);
            -g*m + 0,5*cw*p*%pi*r^2*z(2).^2/m];
    
endfunction
