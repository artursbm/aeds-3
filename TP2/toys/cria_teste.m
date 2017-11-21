clear;
clc;

fileID = fopen('/home/artursbm/GitHub/aeds-3/TP2/toys/in_50000.in','w');
N = 50000;
Mmax = N*(N-1)/2;
M = round(32);
fprintf(fileID,'%i %i\n',N,M);
for i = 1:N
    d = round(rand*10000);
    fprintf(fileID,'%i\n',d);
end
%matriz(N,N) = 0;
for i = 1:M
    x = randi(N);
    y = randi(N);
    while x == y %|| matriz(x,y) == 1 || matriz(y,x) == 1
        x = randi(N);
        y = randi(N);
    end
      matriz(x,y) = 1;
      matriz(y,x) = 1;
    fprintf(fileID,'%i %i\n',x,y);
end
fclose(fileID);