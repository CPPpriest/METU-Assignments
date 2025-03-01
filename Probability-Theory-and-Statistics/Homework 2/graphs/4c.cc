GE_70 = 0;
GE_85 = 0;

for i = 1:1000		
    sample = normrnd(65, 6, 100, 1);
    total = sum(sample > 60 & sample < 75);	
    
    if total >= 70
        GE_70 += 1;
    end
    if total >= 85
        GE_85 += 1;
    end
end

% Results
GE_70
GE_85

