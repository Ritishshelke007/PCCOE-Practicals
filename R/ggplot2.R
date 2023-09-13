# 
ggplot(Placement_dataset, aes(mba_p,salary)) + geom_point()

# to map 2 numerical var and 1 categorical var
# to understand relation between mba_p and salary gender wise
ggplot(Placement_dataset, aes(mba_p,salary,color=gender)) + geom_point()

# map 
ggplot(Placement_dataset, aes(mba_p,salary,color=gender,shape=specialisation)) + geom_point()

ggplot(Placement_dataset, aes(mba_p,salary)) + geom_point() + facet_wrap(~gender)

ggplot(Placement_dataset, aes(mba_p,salary,color=specialisation)) + geom_point() + facet_wrap(~gender)

ggplot(Placement_dataset, aes(mba_p,salary,color=specialisation,shape=workex)) + geom_point() + facet_wrap(~gender)

ggplot(Placement_dataset, aes(mba_p,salary,color=specialisation)) + geom_point() + facet_wrap(~gender) + labs(title = "Gender wise Scatter Plot for mba_p vs salary",x="Mba percentage",y="Salary")

# 
View(diamonds)
help("diamonds")

# filter data set for price > 5000 and < 17500
df1 = filter(diamonds,price>10000,price<11000)
View(df1)

ggplot(df1,aes(depth,price)) + geom_point()

ggplot(df1,aes(depth,price,color=color)) + geom_point()

ggplot(df1,aes(depth,price,color=color,shape=cut)) + geom_point()

ggplot(df1,aes(depth,price,color=color,shape=cut)) + geom_point() + facet_wrap(~clarity)

ggplot(df1,aes(depth,price,color=color,shape=cut)) + geom_point() + facet_wrap(~clarity) + coord_flip()

# box plot 
ggplot(Placement_dataset, aes(salary)) + geom_boxplot() + coord_flip()

summary(Placement_dataset)

ggplot(Placement_dataset, aes(salary,gender)) + geom_boxplot() 

ggplot(Placement_dataset, aes(salary,gender,)) + geom_boxplot() + geom_point() + facet_wrap(~specialisation)

ggplot(Placement_dataset, aes(salary,gender)) + geom_boxplot(color="red",fill="yellow") + geom_point() + facet_wrap(~specialisation) 

ggplot(Placement_dataset, aes(salary,gender)) + geom_boxplot(color="red",fill="yellow") + geom_point(size=3) + facet_wrap(~specialisation) 

# find plot to understand distribution of degree_t and also check
# its distribution as per status 
View(Placement_dataset)

# 
ggplot(Placement_dataset, aes(degree_p,degree_t)) + geom_boxplot(fill="pink") + facet_wrap(~status)

# bar plot - categorical data
ggplot(Placement_dataset, aes(degree_t)) + geom_bar()

ggplot(Placement_dataset, aes(degree_t,fill=status)) + geom_bar()

ggplot(Placement_dataset, aes(degree_t,fill=status)) + geom_bar(position = "dodge") 

ggplot(Placement_dataset, aes(degree_t,fill=status)) + geom_bar(position = "dodge") + facet_wrap(~gender)

ggplot(Placement_dataset, aes(degree_t,fill=status)) + geom_bar(position = "dodge") + facet_wrap(~gender) + coord_flip()

View(diamonds)
# diamond data set 
ggplot(diamonds, aes(cut,fill=color)) + geom_bar(position = "dodge") + facet_wrap(~clarity) 

# create a data frame with 4 cols db, anm(yes/no), sugar, age
# add 4 rows
bp = c(100,150,90,99)
anm = c("Yes","No","No","Yes")
sugar = c(120,88,900,500)
age = c(67,40,20,40)

df = data.frame(bp,anm,sugar,age)
View(df)
