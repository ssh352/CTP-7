clear; clc; close all;


tic
dstruct = importdata('m1801.csv');
toc
t1 = timer('TimerFcn', ...
    '[ActionLine,cp,aa, nTimes,ActionDoneFlg ] = RealTimeDataFunc1( orders,cp,ActionLine,aa, nTimes,ActionDoneFlg );', ...
    'Period', period, ...
    'ExecutionMode', 'fixedSpacing', ...
    'StopFcn', ' ', 'TasksToExecute', N);

delete(timerfind);