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
