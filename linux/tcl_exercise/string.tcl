
set name "Brent Welch"

# string length
puts "string length"
puts "[string length $name]" ;# 11
puts "[string length name]" ;# 4

# string bytelength
puts "string bytelength"
puts "[string bytelength str]" ;# 3
puts "[string bytelength $name]" ;# 11

# string compare, same -> 0
puts "string compare"
puts "[string compare Rick rick]" ;# -1 
puts "[string compare -nocase Rick rick]" ;# 0
puts "[string compare -length 3 rick ricp]" ;# 0

# string equal, same -> 1
puts "string equal"
puts "[string equal Rick rick]" ;# 0
puts "[string equal -nocase Rick rick]" ;# 1

# string first
puts "string first"
puts "[string first rick ilovericktoo]" ;# 5
puts "[string first rick rrickrick]" ;# 1
puts "[string first rick cc]" ;# -1

# string index
puts "string index"
puts "[string index rick 2]" ;# c
puts "[string index rick end]" ;# k
puts "[string index rick end-2]" ; # i

# string last
puts "string last"
puts "[string first rick rickANDrick]" ; # 0
puts "[string last rick rickANDrick]" ; # 7

# string map
puts "string map"
puts "[string map {i c} rick]" ; # rcck
puts "[string map {ri ja} rick]" ; # jack
puts "[string map {r j i a} rick]"; # jack
puts "[string map {rk ju} rick]" ; # rick
puts "[string map {r j k u} rick]"; # jicu

# string match, same -> 1
puts "string match"
puts [string match tcl* tcltk] ; # 1
puts [string match tcl* rick] ; # 0
puts [string match ric? rick] ; # 1
puts [string match ri?? rick] ; # 1
puts [string match ric? rickpeng] ; # 0
puts [string match {[a-z]} rick] ; # 0
puts [string match {[a-z][a-z][a-z][a-z]} rick] ; # 1

# string range
puts "string range"
set r1 [string range iloverick 2 5]
puts $r1 ; # over

# string repeat
puts "string repeat"
puts [string repeat rick 3] ; # rickrickrick

# string replace
puts "string replace"
puts [string replace iloverick 1 4 hate] ; # ihaterick

# string tolower totitle toupper
puts "string tolower totitle toupper"
puts [string tolower ILOVERICK 1 4] ; # IloveRICK
puts [string totitle iloverick 1 4] ; # iLoverick
puts [string toupper iloverick 1 4] ; # iLOVErick

# string trim trimleft trimright
puts "string trim"
puts [string trim ililoverick rick] ; # iliove
puts [string trim kkkloverickkkk rick] ; # love
puts [string trimleft iloverick i] ; # loverick
puts [string trimleft kkkloverickkkk lk] ; # overickkkk
puts [string trimright iloverick rick] ; # ilove

# string wordend wordstart
puts "string wordend wordstart"
puts [string wordend {I love rick} 2] ; # 6
puts [string wordstart iloverick 9] ; # 0









