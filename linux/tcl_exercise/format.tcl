puts [format {%2$s} one two three] ; # two
puts [format {%2$d} one -1 three] ; # -1
puts [format {%2$u} one -1 three] ; # 18446744073709551615
puts [format "%2\$s" one two three] ; # two