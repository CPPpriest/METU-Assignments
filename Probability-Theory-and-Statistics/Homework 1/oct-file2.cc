p = 0.98;
x = 6;

#Range variable for n
N = 50:400;

#Array: Binomial cdf values for ranging n
cdfBinom = zeros(length(N), 1);

#Array: Poisson cdf values for ranging n
cdfPoisson = zeros(length(N), 1);

#Fill arrays for ranging n
for i = 1:length(N)
    n = N(i);
    
    cdfBinom(i) = binocdf(x, n, 0.02);
    
    cdfPoisson(i) = poisscdf(x, (n * 0.02));
end


figure;

plot(N, cdfBinom, 'b-', 'LineWidth', 2);
hold on;
plot(N, cdfPoisson, 'r--', 'LineWidth', 2);

xlabel('n');
ylabel('P');

legend('Binomial', 'Poisson');

grid on;
