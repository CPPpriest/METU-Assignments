import javax.swing.*;
import java.util.ArrayList;

public class SimulationRunner {
    private JFrame window = new JFrame();
    private Display display = new Display();

    private static void stepAllEntities() {
        // TODO
        // In the function, you should:
        // Remove left customers and add new ones as needed
        // Move entities
        // Replenish stocks of all stores on interval (stockReplenishmentFrequency)
        // Note that you should NOT handle transaction logic between customers and
        // stores in here.

        Common.scene.removeLeftCustomers();
        Common.scene.moveAllEntities();
        Common.scene.replenishAllStocks();
        ////
    }

    private static void createAndShowGUI() {
        SimulationRunner runner = new SimulationRunner();
        runner.window.add(runner.display);
        runner.window.setTitle(Common.getTitle());
        runner.window.setSize(Common.getWindowWidth(), Common.getWindowHeight());
        runner.window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        runner.window.setResizable(false);
        runner.window.setLocationRelativeTo(null);
        runner.window.setVisible(true);

        new Timer(5, actionEvent -> {
            stepAllEntities();
            runner.display.repaint();
        }).start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SimulationRunner::createAndShowGUI);
    }
}
