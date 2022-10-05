def build_stdin(in_file: str, out_file: str) -> str:
    final = ""
    final += "------------zqhf-oj-v2-spj-start------------\n"
    final += in_file
    final += '\n' if in_file[-1] != '\n' else ''
    final += "------------zqhf-oj-v2-spj-split------------\n"
    final += out_file
    final += '\n' if out_file[-1] != '\n' else ''
    final += "------------zqhf-oj-v2-spj-end------------\n"
    return final


def parse_result(stdout: str) -> dict:
    stdout = stdout.splitlines(keepends=False)
    stdout[0] = stdout[0].split(' ')
    status = ''
    if stdout[0][0] == '1':
        status = 'Wrong Answer'
    elif stdout[0][0] == '0':
        status = 'Accepted'
    elif stdout[0][0] == '2':
        status = 'System Error'
    else:
        status = 'Unknown Error'
    score = int(stdout[0][1])
    message = stdout[1]
    return {
        'status': status,
        'score': score,
        'message': message
    }
