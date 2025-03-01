// Using Synchronized

public class Scribes {

    private int scribes;
    private int pens;
    private int bottles;


    Scribes(int s, int p, int b){
        scribes = s;
        pens = p;
        bottles = b;
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
        for(int i=1; i <= this.scribes; i++){
            int scribeId = i ;
            new Thread( () -> this.performWriting(scribeId) ).start() ;
        }
    }


    private void performWriting(int scribeId) {
        while (true) {
            synchronized (this) {
                if (pens > 0 && bottles > 0) {
                    pens--;
                    bottles--;
                    break; // Exit the loop once resources are acquired
                }
            }

            // Wait briefly to avoid spinning too fast
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }

        try {
            // Perform actions
            Actions.takeBottle(scribeId);
            Actions.takePen(scribeId);
            Actions.write(scribeId);
            Actions.putBottle(scribeId);
            Actions.putPen(scribeId);
        } finally {
            synchronized (this) {
                pens++;
                bottles++;
            }
        }
    }
}
