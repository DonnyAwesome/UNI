function m = fakultaetrekursiv(n)
    
    select n
    case 0
        m = 1;
    case 1
        m = 1;
    else
        m = n*fakultaetrekursiv(n-1);
    end
endfunction
