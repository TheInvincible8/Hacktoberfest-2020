const canvas=document.querySelector('canvas');
canvas.width=innerWidth;
canvas.height=innerHeight;

const c=canvas.getContext('2d');

class Player{
    constructor(x,y,rad,color){
        this.x=x;
        this.y=y;
        this.rad=rad;
        this.color=color;
    }
    draw(){
        c.beginPath();
        c.arc(this.x,this.y,this.rad,0,Math.PI*2,true);
        c.fillStyle=this.color;
        c.fill()
    }
}
class Projectile{
    constructor(x,y,rad,color,del){
        this.x=x;
        this.y=y;
        this.rad=rad;
        this.color=color;
        this.del=del
    }
    draw(){
        c.beginPath();
        c.arc(this.x,this.y,this.rad,0,Math.PI*2,true);
        c.fillStyle=this.color;
        c.fill()
    }
    update(){
        this.x=this.x+this.del.x;
        this.y=this.y+this.del.y;
        this.draw()
    }
}
var x=canvas.width/2;
var y=canvas.height/2

const player=new Player(x,y,30,'white');

class Enemy{
    constructor(x,y,rad,color,del){
        this.x=x;
        this.y=y;
        this.rad=rad;
        this.color=color;
        this.del=del
    }
    draw(){
        c.beginPath();
        c.arc(this.x,this.y,this.rad,0,Math.PI*2,true);
        c.fillStyle=this.color;
        c.fill()
    }
    update(){
        this.x=this.x+this.del.x;
        this.y=this.y+this.del.y;
        this.draw()
    }
}

class Particle{
    constructor(x,y,rad,color,del){
        this.x=x;
        this.y=y;
        this.rad=rad;
        this.color=color;
        this.del=del;
        this.alpha=1;
    }
    draw(){
        c.save();
        c.globalAlpha=this.alpha;
        c.beginPath();
        c.arc(this.x,this.y,this.rad,0,Math.PI*2,true);
        c.fillStyle=this.color;
        c.fill();
        c.restore();
    }
    update(){
        this.x=this.x+this.del.x;
        this.y=this.y+this.del.y;
        this.alpha-=0.01;
        this.draw();
    }
}

const projectiles=[];
const enemies=[];
const particles=[];

function animate(){
    const anim=requestAnimationFrame(animate);
    c.fillStyle='rgb(0,0,0,0.1)';
    c.fillRect(0,0,canvas.width,canvas.height);
    player.draw();
    projectiles.forEach((p)=>{
        p.update();
    })
    enemies.forEach((e)=>{
        e.update();
        const dist=Math.hypot(e.x-player.x,e.y-player.y);
        //console.log(dist)
        if(dist<=player.rad+e.rad){
            cancelAnimationFrame(anim);
            console.log('end');
        }
    })
    particles.forEach((pp,ip)=>{
        pp.update();
        if(pp.alpha<=0){
            particles.splice(pp,ip);
        }
    })
    //hit
    projectiles.forEach((p,idp)=>{
        enemies.forEach((e,ine)=>{
            const h=Math.hypot(e.x-p.x,e.y-p.y)
            if(e.rad<5){
                enemies.splice(ine,1);
            }
            if(h<(p.rad+e.rad)){
                if(e.rad>5){
                    gsap.to(e,{
                        rad:e.rad-10
                    })
                    projectiles.splice(idp,1);
                    for(var i=0;i<=10;i++){
                        const angle=Math.random()*Math.PI*2;
                        //console.log(angle)
                        particles.push(new Particle(e.x,e.y,2,e.color,{
                            x:Math.cos(angle),
                            y:(Math.sin(angle))*5
                        }))
                    }
                   
                }else{ 
                    projectiles.splice(idp,1);
                    enemies.splice(ine,1);                       
                }   
            }
        })
    })
}

function spawnenemies(){
    setInterval(()=>{
        const rad=30;
        let x;
        let y;
        if(Math.random()<0.5){
            x=Math.random()*canvas.width;
            y=Math.random()<0.5?0-rad:canvas.height+rad;
        }else{
            x=Math.random()<0.5?0-rad:canvas.width+rad;
            y=Math.random()*canvas.height;
        }
        
        const color=`hsl(${Math.random()*360},50%,50%)`;

        const angle=Math.atan2(canvas.height/2-y,canvas.width/2-x);
        const vel={x:Math.cos(angle),y:Math.sin(angle)};
        enemies.push(new Enemy(x,y,rad,color,vel))
    },1000)
}

addEventListener('click',(e)=>{
    const angle=Math.atan2(e.clientY-canvas.height/2,e.clientX-canvas.width/2);
    const vel={x:(Math.cos(angle))*5,y:(Math.sin(angle))*5};
    const projectile=new Projectile(canvas.width/2,canvas.height/2,5,'white',vel);
    projectiles.push(projectile)
})

animate();
spawnenemies();