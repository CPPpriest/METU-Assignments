// Using Semaphore

import java.util.concurrent.Semaphore;


public class Scribes {

    int scribeCount;
    private final Semaphore pens;
    private final Semaphore bottles;

    Scribes(int s, int p, int b){
        scribeCount = s;
        pens = new Semaphore(p, true);
        bottles = new Semaphore(b, true);
    }

    public static void main(String[] args) {
        try{
            int cscribes = Integer.parseInt(args[0]);
            int cpens = Integer.parseInt(args[1]);
            int cbottles = Integer.parseInt(args[2]);
            Scribes proc = new Scribes(cscribes , cpens , cbottles);
            proc.writeAllScribes();
        }catch(Exception e) {
            e.printStackTrace();
        }
    }


    private void writeAllScribes() {
        System.out.println("ScribeCount: " + this.scribeCount);
        for(int i=1; i <= this.scribeCount; i++){
            int scribeId = i ;
            new Thread( () -> this.performWriting(scribeId) ).start() ;
        }
    }

    private void performWriting(int scribeId) {

            try{
                pens.acquire();
                bottles.acquire();

                try{
                    Actions.takeBottle(scribeId);
                    Actions.takePen(scribeId);
                    Actions.write(scribeId);
                }finally{
                    Actions.putPen(scribeId);
                    pens.release();
                    Actions.putBottle(scribeId);
                    bottles.release();
                }
            }catch(Exception e) {

            }

    }
}
