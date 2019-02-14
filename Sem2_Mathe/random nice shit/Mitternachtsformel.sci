function x= loese2(a)
    
    D = sqrt(a(2)^2-4*a(1)*a(3));
    x(1) = (-a(2)+D)/(2*a(1));
    x(2) = (-a(2)-D)/(2*a(1));
    
endfunction
