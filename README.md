
# Load-Bank

Thia is a hardware project that can switch any kind of load bank like capacitor bank.



## Author

- [Prantik Datta](https://github.com/Prantik001)
## Working Principle

Things like money,weight,volume, if they are measured
or counted with respect to some standered value then 
the standered values are taken in the ratio of ```1:2:2:5```

```
like money are made as-
        1 Rs, 2 Rs, 5 Rs, 
        10 Rs, 20 Rs, 50 Rs, 
        100 Rs, 200 Rs, 500 Rs, 
        .......

for example if we have to pay 782 Rs to anyone
then we can take
                1 x 500 Rs.
                2 x 200 Rs.
                1 x 50 Rs.
                1 x 20 Rs.
                1 x 10 Rs.
                1 x 2 Rs. 

to pay the amount.
```
In that way we can make any amount of money. similarly in our prject loads in the same ratio manner. that is -
```
                1    2    2    5
                10   20   20   50
                100  200  200  500
                1000 2000 2000 5000
```
with the help of this we can take maximum amount of 11110 i.e., 10000 + 1000 + 100 + 10

By switching every individual values we can generate desired amount betwnn 0 and 11110.

Main thing is the code behind it that calcuates to switch(select) values to get the desired amount

