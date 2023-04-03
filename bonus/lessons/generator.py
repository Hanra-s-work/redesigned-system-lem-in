#!/bin/env python3
##
# EPITECH PROJECT, 2022
# redesigned-system-lem-in
# File description:
# generator.py
##

from os import system

script = """#!/usr/bin/perl -w

use strict;

# gmin.pl taille densite nb home name end name

if (scalar @ARGV < 3)
{
    print "usage : gmin.pl size density nb_of_fourmiz\nWhen size is the number of rooms and density the percentage of probability of connexions between rooms\n";
    exit -1;
}

my $i = 0;
my $j = 0;

my $size = shift @ARGV;
my $density = int(shift @ARGV);
my $nb = int(shift @ARGV);

my $home = int(rand($size));
my $end  = int(rand($size));
while ($end == $home)
{
    my $end  = int(rand($size));
}

print $nb . "\n";
while ($i < $size)
{
    print "##start\n" if ($i == $home);
    print "##end\n" if ($i == $end);
    print $i;
    print " " . int(rand(10 * $size));
    print " " . int(rand(10 * $size));
    print "\n";
    $i++;
}

$i = 0;

while ($i < $size)
{
    $j = 0;
    while ($j < $size)
    {
	if ($density > int(rand(100)))
	{
	    print $i . "-" . $j . "\n";
	}
	$j++;
    }
    $i++;
}
"""

script_name = "generator.pl"
f = open(script_name, "w", encoding="utf-8")
f.write(script)
f.close()

system(f"chmod +x {script_name}")

nb_ants = int(input("Enter the number of ants:"))
max_end = int(input("Enter the maximum amount of rooms:"))
step_rooms = int(input("Enter the step between each room generation:"))
step = int(input("Enter the step between each generation for the density [min:1, max:99]:"))

nb_tot_generations = 0

for rooms in range(1, max_end, step_rooms):
    for density in range(1, 100, step):
        print(f"Generating generation{nb_tot_generations}_{rooms}_{density}_{nb_ants}.txt")
        system(f"./{script_name} {rooms} {density} {nb_ants} > generation{nb_tot_generations}_{rooms}_{density}_{nb_ants}.txt")
        nb_tot_generations += 1

system(f"rm {script_name}")
