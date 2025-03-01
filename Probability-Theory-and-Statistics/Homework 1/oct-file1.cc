#Total number of days
n = 366; 

#probability of not feeling sick on any given day
p = 0.98; 


#sum pmf from x = 360 to x = 366

totalProb = 0;

for k = 360:366
    prob_k = nchoosek(n, k) * p^k * (1-p)^(n-k);
    totalProb = totalProb + prob_k;
end

#Print result
fprintf('total = %.4f%%\n', totalProb);

