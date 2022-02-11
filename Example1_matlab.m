m = 50;
I = speye(m);
e = ones(m,1);
T = spdiags([e -4*e e],[-1 0 1],m,m);
S = spdiags([e e],[-1 1],m,m);
A = kron(I,T)+kron(S,I);

b = rand(m*m,1);
P = diag(diag(A));
invP = diag(1./diag(A));

B = invP*(P-A);
norm(eig(B),"inf")

L=diag(diag(A)); U=eye(m*m); beta =1; alpha=1;%J
x0 = b;iter =0; x=x0; r=b-A*x0; r0 = norm(r); err = r0 ;y1=[];
while err > 10^(-4) && iter < 100
    z = L\r; z = U\z; iter = iter + 1;
    if beta == 0
        alpha = z'*r/(z'*A*z);
    end
    x=x+ alpha*z;
    r = b - A * x;
    err = norm (r) / r0;
    y1 = [y1 err];
end

L=tril(A); U=eye(m*m); beta =1; alpha=1;%G
x0 = b;iter =0; x=x0; r=b-A*x0; r0 = norm(r); err = r0 ;y2=[];
while err > 10^(-4) && iter < 100
    z = L\r; z = U\z; iter = iter + 1;
    if beta == 0
        alpha = z'*r/(z'*A*z);
    end
    x=x+ alpha*z;
    r = b - A * x;
    err = norm (r) / r0;
    y2 = [y2 err];
end
y = [y1' y2'];
plot(y)
legend('Jacobi','Gauss-Seidel')
xlabel('iteration steps')
ylabel('error')
