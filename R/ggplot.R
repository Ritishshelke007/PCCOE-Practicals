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




