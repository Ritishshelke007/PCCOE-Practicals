let jobArr = [
    {"id":1,"deadline":4,"profit":30},
    {"id":2,"deadline":2,"profit":20},
    {"id":3,"deadline":4,"profit":25},
    {"id":4,"deadline":3,"profit":35},
    {"id":5,"deadline":3,"profit":15},
    {"id":6,"deadline":2,"profit":5},
    {"id":7,"deadline":1,"profit":12},
]


let sortedJob = jobArr.sort((a,b)=>b.profit-a.profit)
console.log(sortedJob);

let maxDeadline = Math.max(...jobArr.map((jobs)=>jobs.deadline))


console.log(sortedJob)
console.log(`max deadline is ${maxDeadline}`);

let deadBool = new Array(maxDeadline+1)
deadBool.fill(-1);
console.log(deadBool);

let count = 0;
let profit = 0;

// result =   if (count < maxDeadline) {
//     jobArr.map((jobs)=>{
//         if (deadBool[jobs.deadline===-1]) {
//             profit+=profit;
//             count+=count;
//             return jobs
//         }
//         else{
//             for(let i = jobs.deadline; i<=1; i--){
//                 if (deadBool[jobs.deadline===-1]) {
//                     result = {...result,jobs}
//                     profit+=profit;
//                     count+=count;
//                 }
                
//             }
            
            
//         }
        
//     })
// }

let result = new Object({});

jobArr.forEach((job)=>{
            for (let i = job.deadline; i >=1; i--) {
                
                if (deadBool[i]===-1) {
                    deadBool[i]=1;
                    profit+=job.profit;
                    console.log(profit);
                    count+=1;
                    console.log(deadBool);
                    console.log(job);

                    result = {...result,job}
                    break;
                }              
            }
        }
})

console.log(`Total profit : ${profit}`);
// console.log(result);






// let result = jobArr.map((job)=>{
//     if (count<maxDeadline) {
//         if (deadBool[job.deadline]===-1) {
//             deadBool[job.deadline]=1;
//             profit+=profit;
//             count+=1;
//             return job
//         }
//         else{
//             for (let i = job.deadline-1; i <=1; i--) {
//                 if (deadBool[i]===-1) {
//                     deadBool[job.deadline]=1;
//                     profit+=profit;
//                     count+=1;
//                     return job
//                 }              
//             }
//         }
//     }

// })



console.log(result);



