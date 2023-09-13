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
