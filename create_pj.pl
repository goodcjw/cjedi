#!/usr/bin/perl
$pj_name = $ARGV[0];
# pj_type?
if($pj_name eq ""){
	die("Please Write An Project Name\n");
}
$pj_name = $pj_name."-sk";
$output = `mkdir $pj_name 2>&1`;
print $output;
if($output =~ /exist/){
	die("Project Exists\n");
}
`cat template_folder/Makefile | sed "s/\\<proj\\>/$pj_name/g" > $pj_name/Makefile`;
`cp template_folder/proj.cc $pj_name/$pj_name.cc`;
`cd $pj_name`;
