m = 500;
b = randn(m,1);
% (a)
% tau = [0.2 0.1 0.05 0.01]; % for (a)
tau = [0.1 0.05 0.01];
res_all = [];
% for k = 1:length(tau)
    R = triu(-1+2*rand(m),1);
    A = R + R';
    for i = 1:m
        for j = 1:m
            if abs(A(i,j)) > tau(3)
                A(i,j) = 0;
            end
        end
    end
    
    A = A + eye(m);
    res = [];
    con = [];
    err = [];
    x = zeros(m,1);
    x_true = A\b;
    r = b-A*x;
    p = r;
    for i = 1:20
        a = r'*r / (p'*A*p);
        x = x + a*p;
        r = r - a * A * p;
        beta = r' * r /(a * p' * A *p);
        p = r + beta * p;
        res = [res norm(r,2)];
        k = sqrt(cond(A));
        con = [con 2*((k-1)/(k+1))^i];
        err = [err norm(x-x_true)/norm(x_true)];
    end
    res_all = [res_all res'];
% end
% semilogy(res_all)

% %(b)
semilogy([con' err'])
legend('tau = 0.01 RHS','tau = 0.01 LHS')
