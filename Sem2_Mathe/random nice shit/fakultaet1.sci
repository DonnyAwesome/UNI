function m = fakultaet1(n)
    
    if n <0 then
        error('no natural number! ');
        
    elseif n == 0
        m = 1;
    else 
        m = n*fakultaet1(n-1);
    end
    
endfunction
