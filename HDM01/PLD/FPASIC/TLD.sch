<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="xc9500xl" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="ticks" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="pha" />
        <signal name="phb" />
        <signal name="clock" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="direction" />
        <signal name="XLXN_23" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <signal name="XLXN_33" />
        <signal name="XLXN_35" />
        <signal name="XLXN_39" />
        <signal name="muxout" />
        <signal name="XLXN_42" />
        <signal name="XLXN_43" />
        <signal name="XLXN_49" />
        <signal name="XLXN_52" />
        <signal name="XLXN_54" />
        <signal name="XLXN_55" />
        <signal name="pwm3" />
        <signal name="pwm2" />
        <signal name="pwm1" />
        <signal name="pwm0" />
        <signal name="XLXN_60" />
        <signal name="XLXN_61" />
        <signal name="XLXN_62" />
        <signal name="XLXN_63" />
        <signal name="XLXN_64" />
        <signal name="XLXN_67" />
        <signal name="XLXN_68" />
        <signal name="XLXN_71" />
        <signal name="XLXN_72" />
        <signal name="XLXN_73" />
        <signal name="XLXN_74" />
        <signal name="XLXN_78" />
        <signal name="XLXN_80" />
        <signal name="XLXN_81" />
        <signal name="XLXN_82" />
        <signal name="XLXN_83" />
        <signal name="XLXN_85" />
        <signal name="XLXN_89" />
        <signal name="XLXN_93" />
        <signal name="XLXN_94" />
        <signal name="XLXN_95" />
        <signal name="XLXN_97" />
        <signal name="XLXN_98" />
        <signal name="XLXN_99" />
        <signal name="XLXN_103" />
        <signal name="XLXN_104" />
        <signal name="XLXN_105" />
        <signal name="XLXN_106" />
        <signal name="XLXN_107" />
        <signal name="XLXN_108" />
        <port polarity="Output" name="ticks" />
        <port polarity="Input" name="pha" />
        <port polarity="Input" name="phb" />
        <port polarity="Input" name="clock" />
        <port polarity="Output" name="direction" />
        <port polarity="Output" name="muxout" />
        <port polarity="Input" name="pwm3" />
        <port polarity="Input" name="pwm2" />
        <port polarity="Input" name="pwm1" />
        <port polarity="Input" name="pwm0" />
        <blockdef name="encoder">
            <timestamp>2017-7-24T17:46:0</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="obuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
        </blockdef>
        <blockdef name="ibuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <blockdef name="cb4ce">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-512" height="448" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="320" y1="-320" y2="-320" x1="384" />
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="32" y1="-64" y2="-64" x1="96" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="64" />
        </blockdef>
        <blockdef name="comp4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-640" height="576" />
            <line x2="320" y1="-352" y2="-352" x1="384" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-384" y2="-384" x1="0" />
            <line x2="64" y1="-448" y2="-448" x1="0" />
            <line x2="64" y1="-576" y2="-576" x1="0" />
            <line x2="64" y1="-512" y2="-512" x1="0" />
            <line x2="64" y1="-320" y2="-320" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="fd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <rect width="256" x="64" y="-320" height="256" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-128" y2="-96" x1="64" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="64" y1="-64" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <block symbolname="encoder" name="XLXI_1">
            <blockpin signalname="XLXN_14" name="rotary_a" />
            <blockpin signalname="XLXN_15" name="rotary_b" />
            <blockpin signalname="XLXN_72" name="clk" />
            <blockpin signalname="XLXN_17" name="detent" />
            <blockpin signalname="XLXN_18" name="dir" />
        </block>
        <block symbolname="obuf" name="XLXI_8">
            <blockpin signalname="XLXN_18" name="I" />
            <blockpin signalname="direction" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_9">
            <blockpin signalname="XLXN_17" name="I" />
            <blockpin signalname="ticks" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_10">
            <blockpin signalname="pha" name="I" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_11">
            <blockpin signalname="phb" name="I" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_12">
            <blockpin signalname="clock" name="I" />
            <blockpin signalname="XLXN_72" name="O" />
        </block>
        <block symbolname="cb4ce" name="XLXI_13">
            <blockpin signalname="XLXN_72" name="C" />
            <blockpin signalname="XLXN_25" name="CE" />
            <blockpin signalname="XLXN_98" name="CLR" />
            <blockpin name="CEO" />
            <blockpin signalname="XLXN_93" name="Q0" />
            <blockpin signalname="XLXN_94" name="Q1" />
            <blockpin signalname="XLXN_95" name="Q2" />
            <blockpin signalname="XLXN_83" name="Q3" />
            <blockpin name="TC" />
        </block>
        <block symbolname="vcc" name="XLXI_15">
            <blockpin signalname="XLXN_25" name="P" />
        </block>
        <block symbolname="comp4" name="XLXI_16">
            <blockpin signalname="XLXN_93" name="A0" />
            <blockpin signalname="XLXN_94" name="A1" />
            <blockpin signalname="XLXN_95" name="A2" />
            <blockpin signalname="XLXN_83" name="A3" />
            <blockpin signalname="pwm0" name="B0" />
            <blockpin signalname="pwm1" name="B1" />
            <blockpin signalname="pwm2" name="B2" />
            <blockpin signalname="pwm3" name="B3" />
            <blockpin signalname="XLXN_60" name="EQ" />
        </block>
        <block symbolname="obuf" name="XLXI_21">
            <blockpin signalname="XLXN_62" name="I" />
            <blockpin signalname="muxout" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_24">
            <blockpin signalname="pwm3" name="I0" />
            <blockpin signalname="pwm2" name="I1" />
            <blockpin signalname="pwm1" name="I2" />
            <blockpin signalname="pwm0" name="I3" />
            <blockpin signalname="XLXN_61" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_25">
            <blockpin signalname="XLXN_61" name="I0" />
            <blockpin signalname="XLXN_60" name="I1" />
            <blockpin signalname="XLXN_89" name="O" />
        </block>
        <block symbolname="fd" name="XLXI_29">
            <blockpin signalname="XLXN_74" name="C" />
            <blockpin signalname="XLXN_99" name="D" />
            <blockpin signalname="XLXN_62" name="Q" />
        </block>
        <block symbolname="comp4" name="XLXI_31">
            <blockpin signalname="XLXN_93" name="A0" />
            <blockpin signalname="XLXN_94" name="A1" />
            <blockpin signalname="XLXN_95" name="A2" />
            <blockpin signalname="XLXN_83" name="A3" />
            <blockpin signalname="XLXN_108" name="B0" />
            <blockpin signalname="XLXN_108" name="B1" />
            <blockpin signalname="XLXN_105" name="B2" />
            <blockpin signalname="XLXN_108" name="B3" />
            <blockpin signalname="XLXN_98" name="EQ" />
        </block>
        <block symbolname="vcc" name="XLXI_32">
            <blockpin signalname="XLXN_108" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_33">
            <blockpin signalname="XLXN_105" name="G" />
        </block>
        <block symbolname="xor2" name="XLXI_36">
            <blockpin signalname="XLXN_89" name="I0" />
            <blockpin signalname="XLXN_99" name="I1" />
            <blockpin signalname="XLXN_74" name="O" />
        </block>
        <block symbolname="comp4" name="XLXI_37">
            <blockpin signalname="XLXN_93" name="A0" />
            <blockpin signalname="XLXN_94" name="A1" />
            <blockpin signalname="XLXN_95" name="A2" />
            <blockpin signalname="XLXN_83" name="A3" />
            <blockpin signalname="XLXN_103" name="B0" />
            <blockpin signalname="XLXN_104" name="B1" />
            <blockpin signalname="XLXN_103" name="B2" />
            <blockpin signalname="XLXN_104" name="B3" />
            <blockpin signalname="XLXN_99" name="EQ" />
        </block>
        <block symbolname="gnd" name="XLXI_39">
            <blockpin signalname="XLXN_103" name="G" />
        </block>
        <block symbolname="vcc" name="XLXI_40">
            <blockpin signalname="XLXN_104" name="P" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="592" y="560" name="XLXI_1" orien="R0">
        </instance>
        <branch name="ticks">
            <wire x2="1424" y1="400" y2="400" x1="1232" />
        </branch>
        <branch name="pha">
            <wire x2="272" y1="384" y2="384" x1="240" />
        </branch>
        <iomarker fontsize="28" x="240" y="384" name="pha" orien="R180" />
        <branch name="phb">
            <wire x2="272" y1="464" y2="464" x1="240" />
        </branch>
        <iomarker fontsize="28" x="240" y="464" name="phb" orien="R180" />
        <branch name="clock">
            <wire x2="272" y1="560" y2="560" x1="240" />
        </branch>
        <iomarker fontsize="28" x="240" y="560" name="clock" orien="R180" />
        <branch name="XLXN_14">
            <wire x2="544" y1="384" y2="384" x1="496" />
            <wire x2="544" y1="384" y2="400" x1="544" />
            <wire x2="592" y1="400" y2="400" x1="544" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="592" y1="464" y2="464" x1="496" />
        </branch>
        <branch name="XLXN_17">
            <wire x2="1008" y1="400" y2="400" x1="976" />
        </branch>
        <iomarker fontsize="28" x="1424" y="400" name="ticks" orien="R0" />
        <iomarker fontsize="28" x="1424" y="528" name="direction" orien="R0" />
        <branch name="XLXN_18">
            <wire x2="1008" y1="528" y2="528" x1="976" />
        </branch>
        <instance x="1008" y="560" name="XLXI_8" orien="R0" />
        <instance x="1008" y="432" name="XLXI_9" orien="R0" />
        <branch name="direction">
            <wire x2="1424" y1="528" y2="528" x1="1232" />
        </branch>
        <instance x="272" y="416" name="XLXI_10" orien="R0" />
        <instance x="272" y="496" name="XLXI_11" orien="R0" />
        <instance x="272" y="592" name="XLXI_12" orien="R0" />
        <instance x="784" y="1312" name="XLXI_13" orien="R0" />
        <instance x="688" y="1008" name="XLXI_15" orien="R0" />
        <branch name="XLXN_25">
            <wire x2="752" y1="1008" y2="1120" x1="752" />
            <wire x2="784" y1="1120" y2="1120" x1="752" />
        </branch>
        <instance x="1552" y="1440" name="XLXI_16" orien="R0" />
        <instance x="2944" y="1168" name="XLXI_21" orien="R0" />
        <branch name="muxout">
            <wire x2="3200" y1="1136" y2="1136" x1="3168" />
        </branch>
        <iomarker fontsize="28" x="3200" y="1136" name="muxout" orien="R0" />
        <instance x="1632" y="1696" name="XLXI_24" orien="R0" />
        <branch name="pwm3">
            <wire x2="1536" y1="1632" y2="1632" x1="1184" />
            <wire x2="1632" y1="1632" y2="1632" x1="1536" />
            <wire x2="1552" y1="1312" y2="1312" x1="1536" />
            <wire x2="1536" y1="1312" y2="1632" x1="1536" />
        </branch>
        <branch name="pwm2">
            <wire x2="1520" y1="1568" y2="1568" x1="1184" />
            <wire x2="1632" y1="1568" y2="1568" x1="1520" />
            <wire x2="1520" y1="1248" y2="1568" x1="1520" />
            <wire x2="1552" y1="1248" y2="1248" x1="1520" />
        </branch>
        <branch name="pwm1">
            <wire x2="1504" y1="1504" y2="1504" x1="1184" />
            <wire x2="1632" y1="1504" y2="1504" x1="1504" />
            <wire x2="1552" y1="1184" y2="1184" x1="1504" />
            <wire x2="1504" y1="1184" y2="1504" x1="1504" />
        </branch>
        <branch name="pwm0">
            <wire x2="1488" y1="1440" y2="1440" x1="1184" />
            <wire x2="1632" y1="1440" y2="1440" x1="1488" />
            <wire x2="1552" y1="1120" y2="1120" x1="1488" />
            <wire x2="1488" y1="1120" y2="1440" x1="1488" />
        </branch>
        <branch name="XLXN_60">
            <wire x2="1968" y1="1088" y2="1088" x1="1936" />
        </branch>
        <instance x="1968" y="1216" name="XLXI_25" orien="R0" />
        <branch name="XLXN_61">
            <wire x2="1952" y1="1536" y2="1536" x1="1888" />
            <wire x2="1952" y1="1152" y2="1536" x1="1952" />
            <wire x2="1968" y1="1152" y2="1152" x1="1952" />
        </branch>
        <branch name="XLXN_62">
            <wire x2="2848" y1="496" y2="496" x1="2832" />
            <wire x2="2848" y1="496" y2="1216" x1="2848" />
            <wire x2="2880" y1="1216" y2="1216" x1="2848" />
            <wire x2="2944" y1="1136" y2="1136" x1="2880" />
            <wire x2="2880" y1="1136" y2="1216" x1="2880" />
        </branch>
        <iomarker fontsize="28" x="1184" y="1632" name="pwm3" orien="R180" />
        <iomarker fontsize="28" x="1184" y="1568" name="pwm2" orien="R180" />
        <iomarker fontsize="28" x="1184" y="1504" name="pwm1" orien="R180" />
        <iomarker fontsize="28" x="1184" y="1440" name="pwm0" orien="R180" />
        <instance x="2448" y="752" name="XLXI_29" orien="R0" />
        <branch name="XLXN_72">
            <wire x2="512" y1="560" y2="560" x1="496" />
            <wire x2="512" y1="560" y2="1184" x1="512" />
            <wire x2="784" y1="1184" y2="1184" x1="512" />
            <wire x2="592" y1="528" y2="528" x1="512" />
            <wire x2="512" y1="528" y2="560" x1="512" />
        </branch>
        <branch name="XLXN_74">
            <wire x2="2448" y1="624" y2="624" x1="2416" />
        </branch>
        <instance x="1600" y="2480" name="XLXI_31" orien="R0" />
        <instance x="1392" y="2224" name="XLXI_32" orien="R0" />
        <instance x="1472" y="2528" name="XLXI_33" orien="R0" />
        <branch name="XLXN_83">
            <wire x2="1216" y1="1056" y2="1056" x1="1168" />
            <wire x2="1552" y1="1056" y2="1056" x1="1216" />
            <wire x2="1216" y1="1056" y2="1072" x1="1216" />
            <wire x2="1216" y1="1072" y2="2096" x1="1216" />
            <wire x2="1600" y1="2096" y2="2096" x1="1216" />
            <wire x2="1296" y1="1072" y2="1072" x1="1216" />
            <wire x2="1296" y1="352" y2="1072" x1="1296" />
            <wire x2="1712" y1="352" y2="352" x1="1296" />
        </branch>
        <branch name="XLXN_89">
            <wire x2="2160" y1="656" y2="656" x1="2080" />
            <wire x2="2080" y1="656" y2="912" x1="2080" />
            <wire x2="2400" y1="912" y2="912" x1="2080" />
            <wire x2="2400" y1="912" y2="1120" x1="2400" />
            <wire x2="2400" y1="1120" y2="1120" x1="2224" />
        </branch>
        <branch name="XLXN_93">
            <wire x2="1392" y1="864" y2="864" x1="1168" />
            <wire x2="1552" y1="864" y2="864" x1="1392" />
            <wire x2="1392" y1="864" y2="1904" x1="1392" />
            <wire x2="1600" y1="1904" y2="1904" x1="1392" />
            <wire x2="1712" y1="160" y2="160" x1="1392" />
            <wire x2="1392" y1="160" y2="864" x1="1392" />
        </branch>
        <branch name="XLXN_94">
            <wire x2="1408" y1="928" y2="928" x1="1168" />
            <wire x2="1552" y1="928" y2="928" x1="1408" />
            <wire x2="1408" y1="928" y2="1888" x1="1408" />
            <wire x2="1520" y1="1888" y2="1888" x1="1408" />
            <wire x2="1520" y1="1888" y2="1968" x1="1520" />
            <wire x2="1600" y1="1968" y2="1968" x1="1520" />
            <wire x2="1712" y1="224" y2="224" x1="1408" />
            <wire x2="1408" y1="224" y2="928" x1="1408" />
        </branch>
        <branch name="XLXN_95">
            <wire x2="1264" y1="992" y2="992" x1="1168" />
            <wire x2="1552" y1="992" y2="992" x1="1264" />
            <wire x2="1264" y1="992" y2="2032" x1="1264" />
            <wire x2="1600" y1="2032" y2="2032" x1="1264" />
            <wire x2="1712" y1="288" y2="288" x1="1264" />
            <wire x2="1264" y1="288" y2="992" x1="1264" />
        </branch>
        <instance x="2160" y="720" name="XLXI_36" orien="R0" />
        <branch name="XLXN_98">
            <wire x2="784" y1="1280" y2="2624" x1="784" />
            <wire x2="2064" y1="2624" y2="2624" x1="784" />
            <wire x2="2064" y1="2128" y2="2128" x1="1984" />
            <wire x2="2064" y1="2128" y2="2624" x1="2064" />
        </branch>
        <branch name="XLXN_99">
            <wire x2="2112" y1="384" y2="384" x1="2096" />
            <wire x2="2112" y1="384" y2="496" x1="2112" />
            <wire x2="2112" y1="496" y2="592" x1="2112" />
            <wire x2="2160" y1="592" y2="592" x1="2112" />
            <wire x2="2448" y1="496" y2="496" x1="2112" />
        </branch>
        <instance x="1712" y="736" name="XLXI_37" orien="R0" />
        <instance x="1584" y="784" name="XLXI_39" orien="R0" />
        <branch name="XLXN_103">
            <wire x2="1648" y1="416" y2="544" x1="1648" />
            <wire x2="1648" y1="544" y2="656" x1="1648" />
            <wire x2="1712" y1="544" y2="544" x1="1648" />
            <wire x2="1712" y1="416" y2="416" x1="1648" />
        </branch>
        <branch name="XLXN_104">
            <wire x2="1584" y1="480" y2="608" x1="1584" />
            <wire x2="1632" y1="608" y2="608" x1="1584" />
            <wire x2="1712" y1="608" y2="608" x1="1632" />
            <wire x2="1712" y1="480" y2="480" x1="1632" />
            <wire x2="1632" y1="480" y2="608" x1="1632" />
        </branch>
        <instance x="1520" y="480" name="XLXI_40" orien="R0" />
        <branch name="XLXN_105">
            <wire x2="1600" y1="2288" y2="2288" x1="1536" />
            <wire x2="1536" y1="2288" y2="2400" x1="1536" />
        </branch>
        <branch name="XLXN_108">
            <wire x2="1456" y1="2224" y2="2240" x1="1456" />
            <wire x2="1504" y1="2240" y2="2240" x1="1456" />
            <wire x2="1504" y1="2224" y2="2240" x1="1504" />
            <wire x2="1584" y1="2224" y2="2224" x1="1504" />
            <wire x2="1600" y1="2224" y2="2224" x1="1584" />
            <wire x2="1584" y1="2224" y2="2352" x1="1584" />
            <wire x2="1600" y1="2352" y2="2352" x1="1584" />
            <wire x2="1600" y1="2160" y2="2160" x1="1584" />
            <wire x2="1584" y1="2160" y2="2224" x1="1584" />
        </branch>
    </sheet>
</drawing>