u = 65;
q = 6;

N = [20, 100, 1000];

for i = 1:3

    sample = normrnd(u, q, N(i), 1);
    
    figure;
    
    hist(sample, 25);
    
    xlabel('Lifespan (years)');
    ylabel('Frequency');
    
end

