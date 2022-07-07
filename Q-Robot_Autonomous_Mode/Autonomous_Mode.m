
clc;
clearvars;
close all;

Laser = rossubscriber('/laser_scan', 'sensor_msgs/LaserScan'); % Cria o subscriber do laser

pub = rospublisher('/cmd_vel'); % Cria o publisher
vel = rosmessage('geometry_msgs/Twist'); % Define o tipo de mensagem

for i = 1:10000
    scandata = receive(Laser,50);
    Obst = min(scandata.Ranges);
    if (Obst < 0.8 && Obst > 0)
        % Fuzzy de desvio de obstáculos
        [Vl,Vang] = Rob_DogObst_Desv(scandata.Ranges, size(scandata.Ranges,1));
        vel.Linear.X = Vl;
        vel.Angular.Z = Vang;
    else
        vel.Linear.X = 0.2;
        vel.Angular.Z = 0;
    end
    
    send(pub,vel);
end