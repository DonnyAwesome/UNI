function [m,b] = gerade(x, y)
    
    
    
    m1 = (y(2)-y(1))/(x(2)-x(1));
    m2 = (y(3)-y(2))/(x(3)-x(2));
    m = (m1 + m2);
    b = y(1) - m*x(1);
    
endfunction
