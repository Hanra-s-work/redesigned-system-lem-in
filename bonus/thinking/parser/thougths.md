# Thougths on how to process the data from the input

## Input

```bash
$> cat anthill
3                                 # <=> nb ants
                                  #_
## start                          # | <=> starting room
0 1 0                             #_|
                                  #_
## end                            # | <=> ending room
1 3 0 #bedroom                    #_|
2 5 0                             # <=> room
# The next room is the kitchen    # <=> ignore
3 9 0
                                  #_
0-2                               #-|--> link between two rooms
2-3                               # |
3-2                               # | possible links
3-4                               #_|
```
