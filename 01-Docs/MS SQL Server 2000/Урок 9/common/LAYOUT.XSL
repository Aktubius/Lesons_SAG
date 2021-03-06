<?xml version="1.0" encoding="windows-1251" ?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/TR/WD-xsl">

<xsl:template match="* | @* | comment() | pi() | text()"><xsl:copy><xsl:apply-templates select="* | @* | comment() | pi() | text()" /></xsl:copy></xsl:template>

<xsl:template match="@���������">
		<xsl:attribute name="title"><xsl:value-of select="." /></xsl:attribute>
</xsl:template>

<xsl:template match="@�����">
		<xsl:attribute name="class"><xsl:value-of select="." /></xsl:attribute>
</xsl:template>

<xsl:template match="�������/@���������">
		<xsl:attribute name="alt"><xsl:value-of select="." /></xsl:attribute>
</xsl:template>

<xsl:template match="�����">
	<p>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</p>
</xsl:template>

<xsl:template match="u">
	<b>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</b>
</xsl:template>

<xsl:template match="a[@target = 'rtop']">
	<xsl:value-of select="." />
</xsl:template>

<xsl:template match="pre/p">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
</xsl:template>

<xsl:template match="font/@face">
	<xsl:attribute name="face">monotype.com, lucida console, monospace</xsl:attribute>
</xsl:template>

<xsl:template match="pre/font/@face | pre/*/font/@face | pre/font/@size | pre/*/font/@size" />

<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!--                       ������ �����  �����                       -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->

<xsl:template match="�������">
	<h1 align="center">
	<u>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</u>
	</h1>
</xsl:template>

<xsl:template match="����">
	<h2 align="center" style="color:maroon">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h2>
</xsl:template>

<xsl:template match="����������">
	<hr />
	<p>
	<b>����������: </b>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</p>
	<hr />
</xsl:template>

<xsl:template match="���������">
	<p>
�������� ��� ���������� ���������� � �����:
	<a>	
		<xsl:attribute name="href"><xsl:value-of select="." /></xsl:attribute>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</a>.
	</p>
</xsl:template>

<xsl:template match="�����������">
	<!--
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	-->
</xsl:template>

<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!--                       ����� �����  �����                       -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->

<xsl:template match="���������[@�������='1'] | ���������">
	<h1>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h1>
</xsl:template>

<xsl:template match="���������[@�������='2']">
	<h2>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h2>
</xsl:template>

<xsl:template match="���������[@�������='3']">
	<h3>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h3>
</xsl:template>

<xsl:template match="���������[@�������='4']">
	<h4>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h4>
</xsl:template>

<xsl:template match="���������[@�������='5']">
	<h5>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h5>
</xsl:template>

<xsl:template match="���������[@�������='6']">
	<h6>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</h6>
</xsl:template>

<xsl:template match="�������">
	<img>
		<xsl:attribute name="src"><xsl:value-of select="@����" /></xsl:attribute>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</img>
</xsl:template>

<xsl:template match="������/�����">
	<li>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</li>
</xsl:template>

<xsl:template match="������ | ������[@���='������']">
	<ul>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</ul>
</xsl:template>

<xsl:template match="������[@���='1']">
	<ol>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</ol>
</xsl:template>

<xsl:template match="������[@���='I'] | ������[@���='�']">
	<ol type="I">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</ol>
</xsl:template>

<xsl:template match="������[@���='A'] | ������[@���='�']">
	<ol type="A">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</ol>
</xsl:template>

<xsl:template match="������[@���='a'] | ������[@���='�']">
	<ol type="a">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</ol>
</xsl:template>

<xsl:template match="���">
	<pre>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</pre>
</xsl:template>

<xsl:template match="����� | �����"><span><xsl:apply-templates select="* | @* | comment() | pi() | text()" /></span></xsl:template>

<xsl:template match="������/@����">
		<xsl:attribute name="href"><xsl:value-of select="." /></xsl:attribute>
</xsl:template>

<xsl:template match="������">
	<a>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</a>
</xsl:template>

<xsl:template match="�����">
	<span>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</span>
</xsl:template>

<xsl:template match="� | �� | ����������">
	<span style="font-weight: bolder;">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</span>
</xsl:template>

<xsl:template match="� | ������">
	<i>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</i>
</xsl:template>

<xsl:template match="�� | �� | ��� | �-� | �-� | ��-� | �-�� | ����������-������ | ����������������">
	<span style="font-weight: bolder; font-style: italic;">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</span>
</xsl:template>

<xsl:template match="������ | ������" />

<xsl:template match="�������">
	<table class="common">
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</table>
</xsl:template>

<xsl:template match="�������/������">
	<tr>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</tr>
</xsl:template>

<xsl:template match="�������/������/������">
	<td>
		<xsl:attribute name="rowSpan"><xsl:value-of select="@������" /></xsl:attribute>
		<xsl:attribute name="colSpan"><xsl:value-of select="@�������" /></xsl:attribute>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</td>
</xsl:template>

<xsl:template match="����� | ����� | �����������">
	<hr>
		<xsl:apply-templates select="* | @* | comment() | pi() | text()" />
	</hr>
</xsl:template>


<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!--                       �������� ����                       -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!--                          � � � �                          -->

<xsl:template match="/����">
	<HTML>
		<head>

			<script language="JavaScript">
				if (top == window) {
					alert('��� �������� ������ ����������� ������ �� �������� ����.\n�� �� ������ ����������� ��� �������� ��� ��������.');
					location.replace('about:blank');
				}
			</script>

			<title><xsl:value-of select="@��������" /></title>
			<link rel="stylesheet" type="text/css" href="../common/style.css" />
		</head>
		<body id="body">
			<table class="headerFooter">
				<tr>
					<td>
						<a accesskey="�" title="������� � ����������� �����">
							<xsl:if test="@����������">
								<xsl:attribute name="href"><xsl:value-of select="@����������" /></xsl:attribute>
							</xsl:if>
							�<u>�</u>�������� ����
						</a>
					</td>
					<td>
						<a accesskey="�" href="index.xml" title="������ ���� ��� �������">
							<u>�</u>���������
						</a>
					</td>
					<td>
						<a accesskey="�" title="������� � ���������� �����">
							<xsl:if test="@���������">
								<xsl:attribute name="href"><xsl:value-of select="@���������" /></xsl:attribute>
							</xsl:if>
							<u>�</u>�������� ����
						</a>
					</td>
				</tr>
			</table>
			<hr />

			<xsl:apply-templates select="/����/*" />

			<hr />
			<table class="headerFooter">
				<tr>
					<td>
						<a accesskey="�" href="javascript:history.back()" title="������� � ������ ��� ������������� ��������">
							<u>�</u>����
						</a>
					</td>
					<td>
						<a accesskey="�" href="javascript:print()" title="���������� ���� ���� �� ��������">
							<u>�</u>�����
						</a>
					</td>
					<td>
						<a accesskey="�" title="������� � ���������� �����">
							<xsl:if test="@���������">
								<xsl:attribute name="href"><xsl:value-of select="@���������" /></xsl:attribute>
							</xsl:if>
							<u>�</u>�������� ����
						</a>
					</td>
				</tr>
			</table>
			<hr />
			
			<xsl:if test="/����[@copyright]">
				<div style="font-size: 60%;">
					<p>
						<xsl:value-of select="./@copyright" />
						���� �������� ������� ������� ������� ���� ��������� ����� � ������ ����� � �������������� ������������ �� ��������� ����� � ������� ������ ������� � ������������� ��� ������������ ������������.
						����� ����������� ��� ���� ��������������� ����� ��������� ���������� �� 2053.
					</p>
				</div>
			</xsl:if>
		</body>
	</HTML>
</xsl:template>

<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->

<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->

<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->

<xsl:template match="������">
	<tr>
		<th colSpan="2">
			<xsl:value-of select="@�����" />
		</th>
	</tr>
	<xsl:apply-templates select="���" />
	<xsl:apply-templates select="�������" order-by="@�����" />
</xsl:template>

<xsl:template match="������[@����]">
	<tr>
		<th colSpan="2">
			<a>
				<xsl:attribute name="href"><xsl:value-of select="@����" /></xsl:attribute>
				<xsl:apply-templates select="@���������" />
				<xsl:value-of select="@�����" />
			</a>
		</th>
	</tr>
	<xsl:apply-templates select="���" />
	<xsl:apply-templates select="�������" order-by="@�����" />
</xsl:template>

<xsl:template match="������/�������">
	<tr>
		<td class="CB">
			<input type="checkbox" value="false">
				<xsl:attribute name="correct"><xsl:value-of select="@�����" /></xsl:attribute>
				<xsl:attribute name="score"><xsl:value-of select="@������" /></xsl:attribute>
			</input>
		</td>
		<td>
			<xsl:value-of select="@�����" />
			<xsl:if test="���">
							<pre style="margin: 0;"><xsl:value-of select="���" /></pre>
			</xsl:if>
		</td>
	</tr>
</xsl:template>

<xsl:template match="������/�������[@����]">
	<tr>
		<td class="CB">
			<input type="checkbox" value="false">
				<xsl:attribute name="correct"><xsl:value-of select="@�����" /></xsl:attribute>
				<xsl:attribute name="score"><xsl:value-of select="@������" /></xsl:attribute>
			</input>
		</td>
		<td>
			<a>
				<xsl:attribute name="href"><xsl:value-of select="@����" /></xsl:attribute>
				<xsl:apply-templates select="@���������" />
				<xsl:value-of select="@�����" />
			</a>
		</td>
	</tr>
</xsl:template>

<xsl:template match="������/���">
	<tr>
		<td colSpan="2">
			<pre style="margin: 0;"><xsl:apply-templates select="* | @* | comment() | pi() | text()" /></pre>
		</td>
	</tr>
</xsl:template>




<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!--                       �������� ����                       -->
<!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->
<!--                          � � � �                          -->

<xsl:template match="/����">
	<HTML>
		<head>
			<title><xsl:value-of select="@��������" /></title>
			<link rel="stylesheet" type="text/css" href="../common/style.css" />
		</head>
		<body id="body" oncontextmenu="return false;">
			<span id="userDataControl" style="behavior: url('#default#userData'); display: none"></span>
			<XML id="userData" onreadystatechange="if ((this.readyState == 'complete') || (this.readyState == 4)) { }"></XML>
			<table class="headerFooter">
				<tr>
					<td>
						<a accesskey="�" title="������� � ����������� �����">
							<xsl:if test="@����������">
								<xsl:attribute name="href"><xsl:value-of select="@����������" /></xsl:attribute>
							</xsl:if>
							�<u>�</u>�������� ����
						</a>
					</td>
					<td>
						<a accesskey="�" href="index.xml" title="������ ���� ��� �������">
							<u>�</u>���������
						</a>
					</td>
					<td>
						<a accesskey="�" title="������� � ���������� �����">
							<xsl:if test="@���������">
								<xsl:attribute name="href"><xsl:value-of select="@���������" /></xsl:attribute>
							</xsl:if>
							<u>�</u>�������� ����
						</a>
					</td>
				</tr>
			</table>
			<hr />
			<h1>
				<xsl:value-of select="@��������" />
			</h1>
			<p>�������� ������ �������� ���������, ����� ���� ������� �� ������ �<u>�</u>���������� �����.</p>
			<p>����� ������������ ����� <a href="../common/test-tips.xml" title="������ �� ������.">��������� ������</a>.</p>
			<hr style="color: windowText; height: 2px;" />

			<table id="testTable">
				<tBody>
					<xsl:apply-templates select="������" order-by="@�����" />
				</tBody>
			</table>

			<hr style="color: windowText; height: 2px;" />
			
			<button accessKey="�" id="checkButton" style="font-size: 100%; height: 1.85em; width: 8.5em;"><u>�</u>���������</button>
			
			<p id="result">��� �������� ������������ ������� � ������ ����� ������ ������� �� ������ �<u>�</u>���������� ������� ����.</p>

			<hr />
			<table class="headerFooter">
				<tr>
					<td>
						<a accesskey="�" href="javascript:history.back()" title="������� � ������ ��� ������������� ��������">
							<u>�</u>����
						</a>
					</td>
					<td>
						<a accesskey="�" href="javascript:print()" title="���������� ����� ����� �� ��������">
							<u>�</u>�����
						</a>
					</td>
					<td>
						<a accesskey="�" title="������� � ���������� �����">
							<xsl:if test="@���������">
								<xsl:attribute name="href"><xsl:value-of select="@���������" /></xsl:attribute>
							</xsl:if>
							<u>�</u>�������� ����
						</a>
					</td>
				</tr>
			</table>

			<script language="JavaScript" type="text/javascript" for="checkButton" event="onclick">
				if (top != window)
					top.check(testTable, result, event.shiftKey)
					if (!event.shiftKey)
						checkButton.disabled = true;
			</script>
			<script language="JavaScript" type="text/javascript" for="body" event="onload">
				if (top != window)
					top.count(testTable)
				else {
					checkButton.disabled = true;
					alert('��� �������� ������ ����������� ������ �� �������� ����.\n�� �� ������ �������� �� ������� ����� ��� ��������, ������� ������ ������������ ���������. ��� � ��������� ��������� � �������� � �������� ���� ������.');
				}
			</script>

		</body>
	</HTML>
</xsl:template>

<xsl:template match="/">
	<xsl:apply-templates select="*" />
</xsl:template>


</xsl:stylesheet>
