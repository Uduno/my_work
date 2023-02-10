import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Vitesse extends JFrame{
    private JPanel Vitesse;
    private JButton backButton;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private JTextField textField1;
    private JTextField textField2;
    private JButton convertirButton;
    private JButton effacerButton;

    public  Vitesse(){
        add(Vitesse);
        setSize(400,400);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        backButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Vitesse.setVisible(false);
                new Acceuil().setVisible(true);
            }
        });

        String s1[] = {"Mach(ma)","km/h","km/s","m/s","mph"};
        for (int i=0; i < s1.length;i++){
            comboBox1.addItem(s1[i]);
            comboBox2.addItem(s1[i]);
        }
    }

    public static double Vitm(String m){
        switch (m){
            case "Mach(ma)":
                return 0.000816;
            case "km/h":
                return 1;
            case "km/s":
                return 0.000278;
            case "m/s":
                return 0.277778;
            case "mph":
                return 1/1.609;
            default:
                break;
        }
        return -1;
    }
    public static void main(String[] args){
        Vitesse v = new Vitesse();
        Num num = new Num();
        JButton btn = v.convertirButton;
        JButton clear = v.effacerButton;

        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String n1 =  v.textField1.getText();
                String n2 = v.textField2.getText();
                JComboBox c1 = v.comboBox1;
                JComboBox c2 = v.comboBox2;
                String cnv1;
                String cnv2;
                if(!n1.isEmpty()){
                    if (!num.isNumeric(n1)){
                        v.textField1.setText("Null");
                        v.textField2.setText("Null");
                        return;
                    }else{
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        System.out.println(cnv1);
                        double coef1 = Vitm(cnv1);
                        double coef2 = Vitm(cnv2);
                        double rslt = (Double.valueOf(n1)*coef1)/(coef2);
                        v.textField2.setText(Double.toString(rslt));
                    }

                } else if (n1.isEmpty() && !n2.isEmpty()) {
                    if (!num.isNumeric(n2)){
                        v.textField1.setText("Null");
                        v.textField2.setText("Null");
                        return;
                    }else {
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        double coef1 = Vitm(cnv1);
                        double coef2 = Vitm(cnv2);
                        double rslt = (Double.valueOf(n2) * coef2) / (coef1);
                        v.textField1.setText(Double.toString(rslt));
                    }
                }


            }
        });
    }
}
