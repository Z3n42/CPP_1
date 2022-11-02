#!/bin/bash
yum update -y
yum install apache2 -y
systemctl start apache2
systemctl enable apache2

aws ec2 run-instances --image-id ami-09d3b3274b6c5d4aa --instance-type t2.micro --count 1 --subnet-id subnet-043eba71241e47e43 --key-name vockey --security-group-ids sg-066562cb7071cf05e --user-data file://apache.sh 

aws ec2 run-instances --image-id ami-09d3b3274b6c5d4aa --instance-type t2.micro --count 1 --subnet-id subnet-0d56bcd29763014e4 --key-name vockey --security-group-ids sg-0dfb33ba5055543d7
