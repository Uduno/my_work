import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Volume extends JFrame {
    private JPanel Volume;
    private JButton backButton;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private JTextField textField1;
    private JTextField textField2;
    private JButton convertirButton;
    private JButton effacerButton;

    public  Volume(){
        add(Volume);
        setSize(400,400);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        backButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Volume.setVisible(false);
                new Acceuil().setVisible(true);
            }
        });

        String s1[] = {"Mètre cube(m³)","Décimètre cube(dm³)","Centimètre cube(cm³)","Millimètre cube(mm³)"
                ,"Litre(l)","Décilitre(dl)","Centilitre(cl)","Millilitre(ml)"};
        for (int i=0; i < s1.length;i++){
            comboBox1.addItem(s1[i]);
            comboBox2.addItem(s1[i]);
        }



    }



    public static double Volm(String m){
        switch (m){
            case "Mètre cube(m³)":
                return 1000;
            case "Décimètre cube(dm³)":
                return 1;
            case "Litre(l)":
                return 1;
            case "Décilitre(dl)":
                return 0.1;
            case "Centilitre(cl)":
                return 0.01;
            case "Centimètre cube(cm³)":
                return 0.001;
            case "Millilitre(ml)":
                return 0.001;
            case "Millimètre cube(mm³)":
                return 0.000001;
            default:
                break;
        }
        return -1;
    }
    public static void main(String[] args){
        Volume v = new Volume();
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
                        double coef1 = Volm(cnv1);
                        double coef2 = Volm(cnv2);
                        double rslt = (Double.valueOf(n1)*coef1)/(coef2);
                        v.textField2.setText(Double.toString(rslt));
                    }

                } else if (n1=="" && !n2.isEmpty()) {
                    if (!num.isNumeric(n2)){
                        v.textField1.setText("Null");
                        v.textField2.setText("Null");
                        return;
                    }else {
                        cnv1 = c1.getSelectedItem().toString();
                        cnv2 = c2.getSelectedItem().toString();
                        double coef1 = Volm(cnv1);
                        double coef2 = Volm(cnv2);
                        double rslt = (Double.valueOf(n2) * coef2) / (coef1);
                        v.textField1.setText(Double.toString(rslt));
                    }
                }


            }
        });

        clear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                v.textField1.setText("");
                v.textField2.setText("");
            }
        });
    }
}
