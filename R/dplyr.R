View(mtcars)

#dplyr 
# select  cols / extract data col wise
df1 = select(mtcars,1:5)
View(df1)

# remove column 
df2 = select(mtcars,-11)
View(df2)

# select rows / extract row(observtion) wise
df3 = slice(mtcars,10:20)
View(df3)

# filter condition 
filter(mtcars,wt>=3)

# add column 
mutate(mtcars,addition=gear+carb)

# summarize 
summarise(mtcars,avg.wt=mean(wt))

# divide data group wise / group the data 
df4 = group_by(mtcars,gear)
View(df4)

# statistical summarize
df5 = summarise(df4,avg=mean(wt))
View(df5)

# find avg 
df6 = summarise(df4,avg=mean(wt),avg2=mean(mpg))
View(df6)

# arrange / sort
arrange(mtcars,gear)

arrange(mtcars,desc(gear))

arrange(mtcars,disp,wt)

arrange(mtcars,gear,wt)

# pipe connect commands 
df7 = mtcars %>% select(1:9) %>% filter(hp>=100) %>% arrange(cyl)
View(df7)

# storms data set
View(storms)

stormsSet = slice(storms,1:100)
View(stormsSet)

# delete NA cols
ss1 = select(stormsSet,-9,-12,-13)
View(ss1)

ss2 = filter(ss1,status=="tropical storm")
View(ss2)

ss2 = arrange(ss2,wind)
View(ss2)

ss2 = ss2 %>%  group_by(name) %>% summarise(avg=mean(wind))
View(ss2)


