import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Temps extends JFrame {
    private JPanel Temps;
    private JButton backButton;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private JTextField textField1;
    private JTextField textField2;
    private JButton convertirButton;
    private JButton effacerButton;

    public  Temps(){
        add(Temps);
        setSize(400,400);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        backButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Temps.setVisible(false);
                new Acceuil().setVisible(true);
            }
        });

        String s1[] = {"Année(a)","Semaine(sm)","Jour(j)","Heure(h)","Minute(m)","Seconde(s)"
                ,"Milliseconde(ms)"};
        for (int i=0; i < s1.length;i++){
            comboBox1.addItem(s1[i]);
            comboBox2.addItem(s1[i]);
        }
    }
    public static double Tmpm(String m){
        switch (m){
            case "Année(a)":
                return 8760*60*60;
            case "Semaine(sm)":
                return 7*24*60*60;
            case "Jour(j)":
                return 24*60*60;
            case "Heure(h)":
                return 60*60;
            case "Minute(m)":
                return 60;
            case "Seconde(s)":
                return 1;
            case "Milliseconde(ms)":
                return 0.001;
            default:
                break;
        }
        return -1;
    }
    public static void main(String[] args){
       Temps t = new Temps();
       Num num = new Num();
       JButton btn = t.convertirButton;
       JButton clear = t.effacerButton;

        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String n1 =  t.textField1.getText();
                String n2 = t.textField2.getText();
                JComboBox c1 = t.comboBox1;
                JComboBox c2 = t.comboBox2;
                String cnv1;
                String cnv2;
                if(!n1.isEmpty()){
                    if (!num.isNumeric(n1)){
                        t.textField1.setText("Null");
                        t.textField2.setText("Null");
                        return;
                    }else{
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        System.out.println(cnv1);
                        double coef1 = Tmpm(cnv1);
                        double coef2 = Tmpm(cnv2);
                        double rslt = (Double.valueOf(n1)*coef1)/(coef2);
                        t.textField2.setText(Double.toString(rslt));
                    }

                } else if (n1.isEmpty() && !n2.isEmpty()) {
                    if (!num.isNumeric(n2)){
                        t.textField1.setText("Null");
                        t.textField2.setText("Null");
                        return;
                    }else {
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        double coef1 = Tmpm(cnv1);
                        double coef2 = Tmpm(cnv2);
                        double rslt = (Double.valueOf(n2) * coef2) / (coef1);
                        t.textField1.setText(Double.toString(rslt));
                    }
                }


            }
        });

        clear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                t.textField1.setText("");
                t.textField2.setText("");
            }
        });
    }
}
