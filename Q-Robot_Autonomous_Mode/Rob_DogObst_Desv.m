
function [Vl,Vang] = Rob_DogObst_Desv(laser, n)

sen_dir = 1;
p = n/3;
for i = 1:p
    if laser(i) < sen_dir
        sen_dir = laser(i);
    end    
end

sen_meio = 1;
for i = p+1:2*p
    if laser(i) < sen_meio
        sen_meio = laser(i);
    end    
end

sen_esq = 1;
for i = 2*p + 1:n
    if laser(i) < sen_esq
        sen_esq = laser(i);
    end    
end

fuzz_obst = readfis('Rob_DogFuzzyDesvObst');

sens = [sen_esq, sen_meio, sen_dir];
sens = double(sens);
output = evalfis(sens, fuzz_obst);
Vl = output(1);
Vang = output(2);
