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
