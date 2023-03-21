# Thoughts on how to process the data from the input

## Table of contens

* [Bash Input](#bash-input)
* [Interesting sections](#interesting-sections)
* [Input](#input)
* [Output](#output)

## Bash Input

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

## Interesting sections

* Number of ants
* Starting zone
* Ending zone
* Rooms
* Links

## Input

Type:

* > char **

Content:

* > file data

## Output

Type:

* > char **

File Name:

* > stdout (1)

File Content:

```md
#number_of_ants
3
#rooms
#start
FirstRoom 2 0
#end
LastRoom 9 0
OtherRooms 2 0
[...]
#tunnels
0-2
[...]
#moves
P1-2
[...]
```

## Method

1. ___Locate___ the number of ants
2. ___Save___ the number of ants
3. ___Locate___ the __starting__ room
4. ___Save___ the __starting__ room
5. ___Locate___ the __end__ room
6. ___Save___ the __end__ room
7. ___While___ __rooms__ still present:\
    1. Locate room
    2. Save room
8. ___While___ __links__ still present:\
    1. ___Locate___ __link__
    2. ___Save___ __link__
9. ___Call___ __Solver__
10. ___Display___ __result__

## Architecture

> {4. / 6. / 7.2. / 8.2.}: Store rooms

```c
typedef struct rooms_s {
    char *name;
    int posx;
    int posy;
    bool is_start;
    bool is_end;
    int nb_occupents;
    const int nb_max_occupents;
} rooms_t;
```

> { 8. }: Find / store links:

```c
enum types {
    STRING;
};
linked_list_t *ll = init_linked_list(0);
append(ll, "2-3", STRING);
```

or

```c
typedef struct tunnel_s {
    int start;
    int end;
    int weight;
} tunnel_t;
```
