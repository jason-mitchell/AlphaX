<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="xc9500xl" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="PHA" />
        <signal name="PHB" />
        <signal name="ECLK" />
        <signal name="IRQ" />
        <signal name="DIR" />
        <signal name="XLXN_15" />
        <signal name="CLK_50" />
        <signal name="XLXN_24" />
        <signal name="LED_0" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="LED_1" />
        <signal name="LED_2" />
        <signal name="XLXN_41" />
        <signal name="MOSI" />
        <signal name="SS" />
        <signal name="SCLK" />
        <signal name="MISO" />
        <signal name="XLXN_66" />
        <signal name="XLXN_73" />
        <signal name="PWMOUT" />
        <signal name="PWMBUS(7:0)" />
        <signal name="XLXN_77" />
        <signal name="PWMBUS(0)" />
        <signal name="PWMBUS(1)" />
        <signal name="PWMBUS(2)" />
        <signal name="PWMBUS(3)" />
        <signal name="MARK(3:0)" />
        <signal name="MARK(0)" />
        <signal name="MARK(1)" />
        <signal name="MARK(2)" />
        <signal name="MARK(3)" />
        <signal name="PWMBUS(4)" />
        <signal name="PWMBUS(5)" />
        <signal name="PWMBUS(6)" />
        <signal name="PWMBUS(7)" />
        <signal name="SPACE(3:0)" />
        <signal name="SPACE(0)" />
        <signal name="SPACE(1)" />
        <signal name="SPACE(2)" />
        <signal name="SPACE(3)" />
        <signal name="LED(3:0)" />
        <signal name="LED(0)" />
        <signal name="LED(1)" />
        <signal name="LED(2)" />
        <signal name="RESET" />
        <signal name="XLXN_79" />
        <port polarity="Input" name="PHA" />
        <port polarity="Input" name="PHB" />
        <port polarity="Input" name="ECLK" />
        <port polarity="Output" name="IRQ" />
        <port polarity="Output" name="DIR" />
        <port polarity="Output" name="CLK_50" />
        <port polarity="Output" name="LED_0" />
        <port polarity="Output" name="LED_1" />
        <port polarity="Output" name="LED_2" />
        <port polarity="Input" name="MOSI" />
        <port polarity="Input" name="SS" />
        <port polarity="Input" name="SCLK" />
        <port polarity="Output" name="MISO" />
        <port polarity="Output" name="PWMOUT" />
        <port polarity="Input" name="RESET" />
        <blockdef name="rotary_decoder">
            <timestamp>2017-8-1T20:24:40</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="ibuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <blockdef name="obuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
        </blockdef>
        <blockdef name="clock_divider">
            <timestamp>2017-8-9T18:54:53</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
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
        <blockdef name="PWM">
            <timestamp>2017-8-13T14:39:13</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
        </blockdef>
        <blockdef name="buf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-64" y2="0" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="128" />
            <line x2="128" y1="0" y2="-32" x1="64" />
        </blockdef>
        <blockdef name="spi">
            <timestamp>2017-8-13T15:13:31</timestamp>
            <rect width="64" x="320" y="340" height="24" />
            <line x2="384" y1="352" y2="352" x1="320" />
            <line x2="0" y1="288" y2="288" x1="64" />
            <line x2="384" y1="224" y2="224" x1="320" />
            <rect width="64" x="320" y="148" height="24" />
            <line x2="384" y1="160" y2="160" x1="320" />
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="256" x="64" y="-128" height="576" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="rotary_decoder" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="rotary_a" />
            <blockpin signalname="XLXN_2" name="rotary_b" />
            <blockpin signalname="XLXN_15" name="clk" />
            <blockpin signalname="XLXN_66" name="detent" />
            <blockpin signalname="XLXN_77" name="dir" />
        </block>
        <block symbolname="ibuf" name="XLXI_3">
            <blockpin signalname="PHA" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_4">
            <blockpin signalname="PHB" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_5">
            <blockpin signalname="ECLK" name="I" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_7">
            <blockpin signalname="XLXN_77" name="I" />
            <blockpin signalname="DIR" name="O" />
        </block>
        <block symbolname="clock_divider" name="XLXI_15">
            <blockpin signalname="XLXN_15" name="clk" />
            <blockpin signalname="XLXN_41" name="clk_out" />
        </block>
        <block symbolname="obuf" name="XLXI_16">
            <blockpin signalname="XLXN_41" name="I" />
            <blockpin signalname="CLK_50" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_18">
            <blockpin signalname="LED(0)" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_19">
            <blockpin signalname="XLXN_24" name="I" />
            <blockpin signalname="LED_0" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_20">
            <blockpin signalname="LED(1)" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_21">
            <blockpin signalname="LED(2)" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_28" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_27">
            <blockpin signalname="XLXN_27" name="I" />
            <blockpin signalname="LED_1" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_28">
            <blockpin signalname="XLXN_28" name="I" />
            <blockpin signalname="LED_2" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_6">
            <blockpin signalname="XLXN_66" name="I" />
            <blockpin signalname="IRQ" name="O" />
        </block>
        <block symbolname="PWM" name="XLXI_48">
            <blockpin signalname="XLXN_15" name="clk" />
            <blockpin signalname="XLXN_79" name="reset" />
            <blockpin signalname="MARK(3:0)" name="rise(3:0)" />
            <blockpin signalname="SPACE(3:0)" name="fall(3:0)" />
            <blockpin signalname="XLXN_73" name="clk_out" />
        </block>
        <block symbolname="obuf" name="XLXI_49">
            <blockpin signalname="XLXN_73" name="I" />
            <blockpin signalname="PWMOUT" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_50">
            <blockpin signalname="PWMBUS(0)" name="I" />
            <blockpin signalname="MARK(0)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_51">
            <blockpin signalname="PWMBUS(1)" name="I" />
            <blockpin signalname="MARK(1)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_52">
            <blockpin signalname="PWMBUS(2)" name="I" />
            <blockpin signalname="MARK(2)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_53">
            <blockpin signalname="PWMBUS(3)" name="I" />
            <blockpin signalname="MARK(3)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_54">
            <blockpin signalname="PWMBUS(4)" name="I" />
            <blockpin signalname="SPACE(0)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_55">
            <blockpin signalname="PWMBUS(5)" name="I" />
            <blockpin signalname="SPACE(1)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_56">
            <blockpin signalname="PWMBUS(6)" name="I" />
            <blockpin signalname="SPACE(2)" name="O" />
        </block>
        <block symbolname="buf" name="XLXI_57">
            <blockpin signalname="PWMBUS(7)" name="I" />
            <blockpin signalname="SPACE(3)" name="O" />
        </block>
        <block symbolname="spi" name="XLXI_58">
            <blockpin signalname="SCLK" name="SCLK" />
            <blockpin signalname="MOSI" name="MOSI" />
            <blockpin signalname="SS" name="SS" />
            <blockpin signalname="RESET" name="NRST" />
            <blockpin signalname="MISO" name="MISO" />
            <blockpin signalname="LED(3:0)" name="LEDPORT(3:0)" />
            <blockpin signalname="PWMBUS(7:0)" name="PWMPORT(7:0)" />
        </block>
        <block symbolname="inv" name="XLXI_59">
            <blockpin signalname="RESET" name="I" />
            <blockpin signalname="XLXN_79" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="624" y="480" name="XLXI_2" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="624" y1="320" y2="320" x1="592" />
        </branch>
        <instance x="368" y="352" name="XLXI_3" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="624" y1="384" y2="384" x1="592" />
        </branch>
        <instance x="368" y="416" name="XLXI_4" orien="R0" />
        <instance x="368" y="480" name="XLXI_5" orien="R0" />
        <branch name="PHA">
            <wire x2="368" y1="320" y2="320" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="320" name="PHA" orien="R180" />
        <branch name="PHB">
            <wire x2="368" y1="384" y2="384" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="384" name="PHB" orien="R180" />
        <branch name="ECLK">
            <wire x2="368" y1="448" y2="448" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="448" name="ECLK" orien="R180" />
        <branch name="IRQ">
            <wire x2="1296" y1="320" y2="320" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1296" y="320" name="IRQ" orien="R0" />
        <branch name="DIR">
            <wire x2="1296" y1="448" y2="448" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1296" y="448" name="DIR" orien="R0" />
        <text style="fontsize:24;fontname:Arial" x="104" y="520">CLOCK: 500Hz from ARM Cortex SysTick</text>
        <branch name="XLXN_15">
            <wire x2="608" y1="448" y2="448" x1="592" />
            <wire x2="624" y1="448" y2="448" x1="608" />
            <wire x2="608" y1="448" y2="528" x1="608" />
            <wire x2="608" y1="528" y2="816" x1="608" />
            <wire x2="720" y1="816" y2="816" x1="608" />
            <wire x2="2128" y1="528" y2="528" x1="608" />
        </branch>
        <instance x="720" y="848" name="XLXI_15" orien="R0">
        </instance>
        <instance x="1472" y="848" name="XLXI_16" orien="R0" />
        <branch name="CLK_50">
            <wire x2="1728" y1="816" y2="816" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1728" y="816" name="CLK_50" orien="R0" />
        <instance x="1888" y="1200" name="XLXI_18" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="2176" y1="1104" y2="1104" x1="2144" />
        </branch>
        <instance x="2176" y="1136" name="XLXI_19" orien="R0" />
        <branch name="LED_0">
            <wire x2="2432" y1="1104" y2="1104" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1104" name="LED_0" orien="R0" />
        <instance x="1888" y="1344" name="XLXI_20" orien="R0" />
        <instance x="1888" y="1488" name="XLXI_21" orien="R0" />
        <branch name="XLXN_27">
            <wire x2="2176" y1="1248" y2="1248" x1="2144" />
        </branch>
        <instance x="2176" y="1280" name="XLXI_27" orien="R0" />
        <branch name="XLXN_28">
            <wire x2="2176" y1="1392" y2="1392" x1="2144" />
        </branch>
        <instance x="2176" y="1424" name="XLXI_28" orien="R0" />
        <branch name="LED_1">
            <wire x2="2432" y1="1248" y2="1248" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1248" name="LED_1" orien="R0" />
        <branch name="LED_2">
            <wire x2="2432" y1="1392" y2="1392" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1392" name="LED_2" orien="R0" />
        <branch name="XLXN_41">
            <wire x2="1312" y1="816" y2="816" x1="1104" />
            <wire x2="1472" y1="816" y2="816" x1="1312" />
            <wire x2="1312" y1="816" y2="1072" x1="1312" />
            <wire x2="1696" y1="1072" y2="1072" x1="1312" />
            <wire x2="1888" y1="1072" y2="1072" x1="1696" />
            <wire x2="1696" y1="1072" y2="1216" x1="1696" />
            <wire x2="1888" y1="1216" y2="1216" x1="1696" />
            <wire x2="1696" y1="1216" y2="1360" x1="1696" />
            <wire x2="1888" y1="1360" y2="1360" x1="1696" />
        </branch>
        <branch name="MOSI">
            <wire x2="432" y1="1248" y2="1248" x1="416" />
            <wire x2="448" y1="1248" y2="1248" x1="432" />
        </branch>
        <branch name="SS">
            <wire x2="432" y1="1312" y2="1312" x1="416" />
            <wire x2="448" y1="1312" y2="1312" x1="432" />
        </branch>
        <branch name="SCLK">
            <wire x2="432" y1="1184" y2="1184" x1="416" />
            <wire x2="448" y1="1184" y2="1184" x1="432" />
        </branch>
        <iomarker fontsize="28" x="416" y="1184" name="SCLK" orien="R180" />
        <iomarker fontsize="28" x="416" y="1248" name="MOSI" orien="R180" />
        <iomarker fontsize="28" x="416" y="1312" name="SS" orien="R180" />
        <branch name="MISO">
            <wire x2="864" y1="1504" y2="1504" x1="832" />
        </branch>
        <iomarker fontsize="28" x="864" y="1504" name="MISO" orien="R0" />
        <branch name="XLXN_66">
            <wire x2="1040" y1="320" y2="320" x1="1008" />
        </branch>
        <instance x="1040" y="352" name="XLXI_6" orien="R0" />
        <instance x="1040" y="480" name="XLXI_7" orien="R0" />
        <instance x="2128" y="752" name="XLXI_48" orien="R0">
        </instance>
        <branch name="XLXN_73">
            <wire x2="2544" y1="528" y2="528" x1="2512" />
        </branch>
        <instance x="2544" y="560" name="XLXI_49" orien="R0" />
        <branch name="PWMOUT">
            <wire x2="3136" y1="528" y2="528" x1="2768" />
        </branch>
        <iomarker fontsize="28" x="3136" y="528" name="PWMOUT" orien="R0" />
        <branch name="PWMBUS(7:0)">
            <wire x2="912" y1="1632" y2="1632" x1="832" />
            <wire x2="912" y1="1632" y2="2576" x1="912" />
            <wire x2="2848" y1="2576" y2="2576" x1="912" />
            <wire x2="2848" y1="1328" y2="1424" x1="2848" />
            <wire x2="2848" y1="1424" y2="1504" x1="2848" />
            <wire x2="2848" y1="1504" y2="1600" x1="2848" />
            <wire x2="2848" y1="1600" y2="1696" x1="2848" />
            <wire x2="2848" y1="1696" y2="1904" x1="2848" />
            <wire x2="2848" y1="1904" y2="1984" x1="2848" />
            <wire x2="2848" y1="1984" y2="2064" x1="2848" />
            <wire x2="2848" y1="2064" y2="2160" x1="2848" />
            <wire x2="2848" y1="2160" y2="2576" x1="2848" />
        </branch>
        <branch name="XLXN_77">
            <wire x2="1040" y1="448" y2="448" x1="1008" />
        </branch>
        <bustap x2="2944" y1="1424" y2="1424" x1="2848" />
        <bustap x2="2944" y1="1504" y2="1504" x1="2848" />
        <bustap x2="2944" y1="1600" y2="1600" x1="2848" />
        <bustap x2="2944" y1="1696" y2="1696" x1="2848" />
        <branch name="PWMBUS(0)">
            <wire x2="3008" y1="1424" y2="1424" x1="2944" />
        </branch>
        <branch name="PWMBUS(1)">
            <wire x2="3008" y1="1504" y2="1504" x1="2944" />
        </branch>
        <branch name="PWMBUS(2)">
            <wire x2="3008" y1="1600" y2="1600" x1="2944" />
        </branch>
        <branch name="PWMBUS(3)">
            <wire x2="3008" y1="1696" y2="1696" x1="2944" />
        </branch>
        <instance x="3008" y="1456" name="XLXI_50" orien="R0" />
        <instance x="3008" y="1536" name="XLXI_51" orien="R0" />
        <instance x="3008" y="1632" name="XLXI_52" orien="R0" />
        <instance x="3008" y="1728" name="XLXI_53" orien="R0" />
        <branch name="MARK(3:0)">
            <wire x2="2128" y1="656" y2="656" x1="2048" />
            <wire x2="2048" y1="656" y2="864" x1="2048" />
            <wire x2="3440" y1="864" y2="864" x1="2048" />
            <wire x2="3440" y1="864" y2="1424" x1="3440" />
            <wire x2="3440" y1="1424" y2="1504" x1="3440" />
            <wire x2="3440" y1="1504" y2="1600" x1="3440" />
            <wire x2="3440" y1="1600" y2="1696" x1="3440" />
            <wire x2="3440" y1="1696" y2="1728" x1="3440" />
        </branch>
        <bustap x2="3344" y1="1424" y2="1424" x1="3440" />
        <bustap x2="3344" y1="1504" y2="1504" x1="3440" />
        <bustap x2="3344" y1="1600" y2="1600" x1="3440" />
        <bustap x2="3344" y1="1696" y2="1696" x1="3440" />
        <branch name="MARK(0)">
            <wire x2="3344" y1="1424" y2="1424" x1="3232" />
        </branch>
        <branch name="MARK(1)">
            <wire x2="3344" y1="1504" y2="1504" x1="3232" />
        </branch>
        <branch name="MARK(2)">
            <wire x2="3344" y1="1600" y2="1600" x1="3232" />
        </branch>
        <branch name="MARK(3)">
            <wire x2="3344" y1="1696" y2="1696" x1="3232" />
        </branch>
        <bustap x2="2944" y1="1904" y2="1904" x1="2848" />
        <bustap x2="2944" y1="1984" y2="1984" x1="2848" />
        <bustap x2="2944" y1="2064" y2="2064" x1="2848" />
        <bustap x2="2944" y1="2160" y2="2160" x1="2848" />
        <branch name="PWMBUS(4)">
            <wire x2="3008" y1="1904" y2="1904" x1="2944" />
        </branch>
        <branch name="PWMBUS(5)">
            <wire x2="3008" y1="1984" y2="1984" x1="2944" />
        </branch>
        <branch name="PWMBUS(6)">
            <wire x2="3008" y1="2064" y2="2064" x1="2944" />
        </branch>
        <branch name="PWMBUS(7)">
            <wire x2="3008" y1="2160" y2="2160" x1="2944" />
        </branch>
        <instance x="3008" y="1936" name="XLXI_54" orien="R0" />
        <instance x="3008" y="2016" name="XLXI_55" orien="R0" />
        <instance x="3008" y="2096" name="XLXI_56" orien="R0" />
        <instance x="3008" y="2192" name="XLXI_57" orien="R0" />
        <branch name="SPACE(3:0)">
            <wire x2="2128" y1="720" y2="720" x1="2096" />
            <wire x2="2096" y1="720" y2="816" x1="2096" />
            <wire x2="3488" y1="816" y2="816" x1="2096" />
            <wire x2="3488" y1="816" y2="1840" x1="3488" />
            <wire x2="3488" y1="1840" y2="1840" x1="3376" />
            <wire x2="3376" y1="1840" y2="1904" x1="3376" />
            <wire x2="3376" y1="1904" y2="1984" x1="3376" />
            <wire x2="3376" y1="1984" y2="2064" x1="3376" />
            <wire x2="3376" y1="2064" y2="2160" x1="3376" />
            <wire x2="3376" y1="2160" y2="2224" x1="3376" />
        </branch>
        <bustap x2="3280" y1="1904" y2="1904" x1="3376" />
        <bustap x2="3280" y1="1984" y2="1984" x1="3376" />
        <bustap x2="3280" y1="2064" y2="2064" x1="3376" />
        <bustap x2="3280" y1="2160" y2="2160" x1="3376" />
        <branch name="SPACE(0)">
            <wire x2="3280" y1="1904" y2="1904" x1="3232" />
        </branch>
        <branch name="SPACE(1)">
            <wire x2="3280" y1="1984" y2="1984" x1="3232" />
        </branch>
        <branch name="SPACE(2)">
            <wire x2="3280" y1="2064" y2="2064" x1="3232" />
        </branch>
        <branch name="SPACE(3)">
            <wire x2="3280" y1="2160" y2="2160" x1="3232" />
        </branch>
        <branch name="LED(3:0)">
            <wire x2="1072" y1="1440" y2="1440" x1="832" />
            <wire x2="1072" y1="1440" y2="1744" x1="1072" />
            <wire x2="1344" y1="1744" y2="1744" x1="1072" />
            <wire x2="1344" y1="1104" y2="1168" x1="1344" />
            <wire x2="1344" y1="1168" y2="1264" x1="1344" />
            <wire x2="1344" y1="1264" y2="1344" x1="1344" />
            <wire x2="1344" y1="1344" y2="1440" x1="1344" />
            <wire x2="1344" y1="1440" y2="1744" x1="1344" />
        </branch>
        <bustap x2="1440" y1="1168" y2="1168" x1="1344" />
        <bustap x2="1440" y1="1264" y2="1264" x1="1344" />
        <bustap x2="1440" y1="1344" y2="1344" x1="1344" />
        <branch name="LED(0)">
            <wire x2="1664" y1="1168" y2="1168" x1="1440" />
            <wire x2="1664" y1="1136" y2="1168" x1="1664" />
            <wire x2="1888" y1="1136" y2="1136" x1="1664" />
        </branch>
        <branch name="LED(1)">
            <wire x2="1664" y1="1264" y2="1264" x1="1440" />
            <wire x2="1664" y1="1264" y2="1280" x1="1664" />
            <wire x2="1888" y1="1280" y2="1280" x1="1664" />
        </branch>
        <branch name="LED(2)">
            <wire x2="1664" y1="1344" y2="1344" x1="1440" />
            <wire x2="1664" y1="1344" y2="1424" x1="1664" />
            <wire x2="1888" y1="1424" y2="1424" x1="1664" />
        </branch>
        <instance x="448" y="1280" name="XLXI_58" orien="R0">
        </instance>
        <branch name="RESET">
            <wire x2="144" y1="1008" y2="1456" x1="144" />
            <wire x2="368" y1="1456" y2="1456" x1="144" />
            <wire x2="368" y1="1456" y2="1568" x1="368" />
            <wire x2="448" y1="1568" y2="1568" x1="368" />
            <wire x2="864" y1="1008" y2="1008" x1="144" />
            <wire x2="368" y1="1568" y2="1568" x1="272" />
        </branch>
        <iomarker fontsize="28" x="272" y="1568" name="RESET" orien="R180" />
        <instance x="864" y="1040" name="XLXI_59" orien="R0" />
        <branch name="XLXN_79">
            <wire x2="1968" y1="1008" y2="1008" x1="1088" />
            <wire x2="2128" y1="592" y2="592" x1="1968" />
            <wire x2="1968" y1="592" y2="976" x1="1968" />
            <wire x2="1968" y1="976" y2="1008" x1="1968" />
        </branch>
    </sheet>
</drawing>