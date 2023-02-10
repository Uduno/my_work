import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Acceuil extends JFrame {
    private JPanel Acceuil;
    private JButton tempsButton;
    private JButton températureButton;
    private JButton volumeButton;
    private JButton vitesseButton;
    private JButton exitButton;

    public Acceuil(){
        add(Acceuil);
        setSize(400,400);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        tempsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Acceuil.setVisible(false);
                new Temps().setVisible(true);
            }
        });

        volumeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Acceuil.setVisible(false);
                new Volume().setVisible(true);
            }
        });

        vitesseButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Acceuil.setVisible(false);
                new Vitesse().setVisible(true);
            }
        });

        températureButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Acceuil.setVisible(false);
                new Température().setVisible(true);
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
    }



    public static void main (String[] args){
        Acceuil acceuil = new Acceuil();

    }
}
