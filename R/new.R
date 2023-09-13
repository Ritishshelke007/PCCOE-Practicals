x = 2000

# this is a comment 
# Week 1 How to use data set in R software 
# data set handling methods
# use of in build data set 

# show all data sets available
data();

# view data set V
View(iris);

# to check observation (variables(columns) obs(rows))
str(iris)

# change the name of data set 
data = iris

# view all of data sets with all packages that 
# can be accessed when
# packages are installed

data(package = .packages(all.available = TRUE))

# show statistic of num variables of data set
summary(data)

# vector
Vec = c(10,20,30,40)

# Create data frame 
Product.name = c('Redmi','Realme','Apple')
Product.qty = c(10,50,20)
Product.price = c(10000,30000,50000)

Product.dataset = data.frame(Product.name,Product.qty,Product.price)


# question - create a data frame with 4 variables 
# raw material, transport, quality(G,A,B), price
raw.material = c('LithiumIon','Keyboardkeys','Copper','Aluminium')
transport = c('train','bus','havaiyatra','goodsCarrier')
quality = c('good','average','bad','good')
price = c(3904240, 349120, 984737, 4756473)

shipping = data.frame(raw.material, transport, quality, price)

View(shipping)

# kaggle, github, uci data set 2 3 
# done

data()
View(Titanic)
data = data.frame(Titanic)

spreadOne = spread(data,Sex,Freq)
View(spreadOne)

popData = data.frame(population)
View(popData)
spreadPop = spread(popData, year, population)
View(spreadPop)

gatherrPop = gather(spreadPop, "Year","Population",2:20)
View(gatherrPop)

# spread marketing 
spreadMark = spread(marketing_campaign_marketing_campaign,Marital_Status,Income)
View(spreadMark)

# gather
gatherMark = gather(spreadMark, "Campaign","Total",19:23)
View(gatherMark)

# separate 
sepMark = separate(marketing_campaign_marketing_campaign,Dt_Customer,c("Day","Month","Year"))
View(sepMark)

# handling missing values

# structure of data set
str(marketing_campaign_marketing_campaign)

# info about numerical data
summary(marketing_campaign_marketing_campaign)

#identify NAs in specific data frame column
is.na(marketing_campaign_marketing_campaign$Income)

is.na(marketing_campaign_marketing_campaign$Year_Birth)

is.na(marketing_campaign_marketing_campaign)

# identify location of NAs in vector
which(is.na(marketing_campaign_marketing_campaign$Income))

# identify count if NAa in data frame
sum(is.na(marketing_campaign_marketing_campaign$Income))

# for data frames a convenient shortcut to compute the total 
# in each column is to use colSums()
colSums(is.na(marketing_campaign_marketing_campaign))

# re code missing value with mean
mean(marketing_campaign_marketing_campaign$Income)

marketing_campaign_marketing_campaign[is.na(marketing_campaign_marketing_campaign)]<- mean(marketing_campaign_marketing_campaign$Income,na.rm = TRUE)
# na.rm -> remove NA
round(marketing_campaign_marketing_campaign$Income, 0)

View(storms)
colSums(is.na(Placement_dataset))

# data frame that codes missing value as 99
df <- data.frame(col1= c(1:3,99),col2=c(2.5,4.2,99,3.2))

# change 99s to NAs
df[df == 99] <- NA
df

# alternate commands

# na.omit : omits every row containing even one NA
placement_new <- na.omit(Placement_dataset)
View(placement_new)

# na.exclude : excludes every row containing even one NA but keeops a record their original positiion
placement_new_2 <- na.exclude(placement_new)
View(placement_new_2)

# na.pass: it just 

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


View(diamonds)
View(mpg)

# bar plot for univariate categorical variable 
ggplot(mpg, aes(class)) + geom_bar()

ggplot(mpg, aes(class)) + geom_bar(width=0.3)

ggplot(mpg, aes(class)) + geom_bar(width=0.3,color="Red")

ggplot(mpg, aes(class)) + geom_bar(width=0.3,color="Red",fill="red")

ggplot(mpg, aes(class)) + geom_line()

ggplot(mpg, aes(class)) + geom_dotplot(fill="red")

ggplot(mpg, aes(class)) + geom_boxplot(width=10,color="Red",fill="red")

# bivariate
ggplot(mpg, aes(cty,displ)) + geom_point(size=3,color="violet")

# to understand two numerical variable point (scatter plot)
# is used
# to understand distribution of univariate numerical data
# for univariate numerical data

ggplot(mpg,aes(cty))+geom_boxplot()
summary(mpg)
ggplot(mpg,aes(displ))+geom_boxplot()

ggplot(mpg,aes(displ))+geom_histogram()
ggplot(mpg,aes(displ))+geom_histogram(binwidth = 1,color="black",fill="transparent")




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
